#include "MP_GROVE_101020132.h"

MP_GROVE_101020132::MP_GROVE_101020132(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_GROVE_101020132::init() 
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}

double MP_GROVE_101020132::getPercent()
{
    MP_Log::i(tag,(analogRead(pin)/1023.0)*100);
	return (analogRead(pin)/1023.0)*100;
}
