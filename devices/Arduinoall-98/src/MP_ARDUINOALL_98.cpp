#include "MP_ARDUINOALL_98.h"

MP_ARDUINOALL_98::MP_ARDUINOALL_98(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_98::init() 
{
    pinMode(this->pin,INPUT);
}

double MP_ARDUINOALL_98::getPercent()
{
    return (analogRead(pin)/1023.0)*100;
}
