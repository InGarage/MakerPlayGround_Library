#include "MP_ARDUINOALL_29.h"

MP_ARDUINOALL_29::MP_ARDUINOALL_29(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_29::init() 
{
    pinMode(this->pin,INPUT);
    MP_Log::i(tag,"Ready");
}

int MP_ARDUINOALL_29::isDetected() 
{
    MP_Log::i(tag,"Detected");
    return  digitalRead(pin) == HIGH;

}

int MP_ARDUINOALL_29::isNotDetected()
{
    MP_Log::i(tag,"Not detected");
    return  digitalRead(pin) == LOW;
}