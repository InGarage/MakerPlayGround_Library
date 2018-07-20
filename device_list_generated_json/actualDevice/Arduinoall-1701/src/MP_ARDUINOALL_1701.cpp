#include "MP_ARDUINOALL_1701.h"

MP_ARDUINOALL_1701::MP_ARDUINOALL_1701(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_1701::init()
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}

int MP_ARDUINOALL_1701::isDetected()
{
  MP_Log::i(tag,"Detected");
  return  digitalRead(pin) == LOW;
}

int MP_ARDUINOALL_1701::isNotDetected()
{
  MP_Log::i(tag,"Not detected");
  return  digitalRead(pin) == HIGH;
}
