#include "MP_GROVE_101020017.h"

MP_GROVE_101020017::MP_GROVE_101020017(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  
}

void MP_GROVE_101020017::init() 
{
	pinMode(this->pin,INPUT);
}


double MP_GROVE_101020017::getPercent()
{
	return (analogRead(pin)/1023.0)*100;
}
