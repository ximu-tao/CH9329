#include "Arduino.h"


#include "Arduino.h"
#include "CH9329.h"

void setup(){

    delay( 1000 );

    CH9329 ch9329 = CH9329( &Serial );
    ch9329.pressASCII('H');
    ch9329.releaseAll();
    ch9329.pressASCII('e');
    ch9329.releaseAll();
    ch9329.pressASCII('l');
    ch9329.releaseAll();
    ch9329.pressASCII('l');
    ch9329.releaseAll();
    ch9329.pressASCII('o');
    ch9329.releaseAll();
    ch9329.pressASCII(' ');
    ch9329.releaseAll();
    ch9329.pressASCII('W');
    ch9329.releaseAll();
    ch9329.pressASCII('o');
    ch9329.releaseAll();
    ch9329.pressASCII('r');
    ch9329.releaseAll();
    ch9329.pressASCII('l');
    ch9329.releaseAll();
    ch9329.pressASCII('d');
    ch9329.releaseAll();
    ch9329.pressASCII('\n');
    ch9329.releaseAll();

    char * str = "Hello World";
    ch9329.sendString( str , 11 );
}


void loop(){

}