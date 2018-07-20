#include "MP_ARDUINOALL_98.h"

MP_ARDUINOALL_98::MP_ARDUINOALL_98(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_98::init() 
{
    pinMode(this->pin,INPUT);
    MP_Log::i(tag,"Ready");
}

double MP_ARDUINOALL_98::getPercent()
{
    MP_Log::i(tag,(analogRead(pin)/1023.0)*100);
    return (analogRead(pin)/1023.0)*100;
}
