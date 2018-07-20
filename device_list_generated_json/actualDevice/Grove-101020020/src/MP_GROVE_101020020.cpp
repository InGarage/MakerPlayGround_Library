#include "MP_GROVE_101020020.h"

MP_GROVE_101020020::MP_GROVE_101020020(uint8_t pin)
  : pin(pin)
{
}

void MP_GROVE_101020020::init() 
{
	pinMode(this->pin,INPUT);
}

int MP_GROVE_101020020::isDetected() 
{
  return  digitalRead(pin) == HIGH;
}

int MP_GROVE_101020020::isNotDetected()
{
  return  digitalRead(pin) == LOW;
}
