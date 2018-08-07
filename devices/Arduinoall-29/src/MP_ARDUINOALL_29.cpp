#include "MP_ARDUINOALL_29.h"

MP_ARDUINOALL_29::MP_ARDUINOALL_29(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_29::init() 
{
    pinMode(this->pin,INPUT);
}

int MP_ARDUINOALL_29::isDetected() 
{
    return  digitalRead(pin) == HIGH;

}

int MP_ARDUINOALL_29::isNotDetected()
{
    return  digitalRead(pin) == LOW;
}