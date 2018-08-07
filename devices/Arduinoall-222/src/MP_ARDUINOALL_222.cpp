#include "MP_ARDUINOALL_222.h"

MP_ARDUINOALL_222::MP_ARDUINOALL_222(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_222::init() 
{
	pinMode(this->pin,INPUT);
}


double MP_ARDUINOALL_222::getPercent()
{
	return (analogRead(pin)/1023.0)*100;
}
