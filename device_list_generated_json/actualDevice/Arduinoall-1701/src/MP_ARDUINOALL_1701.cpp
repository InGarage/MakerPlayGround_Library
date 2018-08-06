#include "MP_ARDUINOALL_1701.h"

MP_ARDUINOALL_1701::MP_ARDUINOALL_1701(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_1701::init()
{
	pinMode(this->pin,INPUT);
}

int MP_ARDUINOALL_1701::isDetected()
{
  return  digitalRead(pin) == LOW;
}

int MP_ARDUINOALL_1701::isNotDetected()
{
  return  digitalRead(pin) == HIGH;
}
