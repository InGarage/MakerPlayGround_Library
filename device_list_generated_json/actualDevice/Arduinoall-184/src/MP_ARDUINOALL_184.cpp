#include "MP_ARDUINOALL_184.h"

MP_ARDUINOALL_184::MP_ARDUINOALL_184(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_184::init() 
{
	pinMode(this->pin,INPUT);
}

double MP_ARDUINOALL_184::getHumidity() 
{
	return (analogRead(pin)/1023.0)*100.0;
}
