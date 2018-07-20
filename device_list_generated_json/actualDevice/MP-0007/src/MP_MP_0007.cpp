#include "MP_MP_0007.h"

MP_MP_0007::MP_MP_0007(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_MP_0007::init() 
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}

double MP_MP_0007::getPercent()
{
    MP_Log::i(tag,(analogRead(pin)/1023.0)*100);
	return (analogRead(pin)/1023.0)*100;
}
