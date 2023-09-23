#include "CH9329.h"



CH9329::CH9329(  HardwareSerial * serial, uint32_t baud , uint8_t addr ) {
    this->_serial = serial;
    _serial->begin(baud);
}

uart_fmt CH9329::getInfo() {
    this->writeHeadAddr();
    _serial->write( CMD_GET_INFO );
    _serial->write( 0x00 );
    _serial->write( 0x03 );

    return this->readUart();
}


uart_fmt CH9329::sendKbGeneralData( uint8_t * key ) {
    this->writeHeadAddr();
    _serial->write( CMD_SEND_KB_GENERAL_DATA );
    _serial->write( 0x08 );

    _serial->write( key , 8 );


    return this->readUart();

}

void CH9329::writeUart(uart_fmt *data) {
    data->HEAD[0] = 0x57;
    data->HEAD[1] = 0xAB;
    data->ADDR = this->_addr;

    data->SUM = data->HEAD[0] + data->HEAD[1] + this->_addr + data->CMD + data->LEN;

    _serial->write( data->HEAD[0] );
    _serial->write( data->HEAD[1] );
    _serial->write( data->ADDR );
    _serial->write( data->CMD );
    _serial->write( data->LEN );

    for (int i = 0; i < data->LEN; ++i) {
        data->SUM += data->DATA[i];
        _serial->write( data->DATA[i] );
    }

    _serial->write( data->SUM & 0xFF );
}

uart_fmt CH9329::readUart() {
    uart_fmt info{};
    _serial->read( (byte *)&info , 5 );
    _serial->read( (byte *)&(info.DATA) , info.LEN );
    _serial->read( (byte *)&(info.SUM) , 1 );
    return info;
}


