#include "MP_ARDUINOALL_261.h"

MP_ARDUINOALL_261::MP_ARDUINOALL_261(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  
}

void MP_ARDUINOALL_261::init() 
{
	pinMode(this->pin,INPUT);
}


double MP_ARDUINOALL_261::getPercent()
{
	return (analogRead(pin)/1023.0)*100;
}
