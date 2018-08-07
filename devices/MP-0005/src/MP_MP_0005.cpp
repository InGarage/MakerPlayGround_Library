#include "MP_MP_0005.h"

MP_MP_0005::MP_MP_0005(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_MP_0005::init() 
{
	pinMode(this->pin,INPUT);
}


double MP_MP_0005::getPercent()
{
	return (analogRead(pin)/1023.0)*100;
}
