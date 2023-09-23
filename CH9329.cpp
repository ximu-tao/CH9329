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

void CH9329::writeHeadAddr() {
    this->_serial->write( 0x57 );
    this->_serial->write( 0xAB );
    this->_serial->write( this->_addr );
}

uart_fmt CH9329::readUart() {
    uart_fmt info{};
    _serial->read( (byte *)&info , 5 );
    _serial->read( (byte *)&(info.DATA) , info.LEN );
    _serial->read( (byte *)&(info.SUM) , 1 );
    return info;
}


