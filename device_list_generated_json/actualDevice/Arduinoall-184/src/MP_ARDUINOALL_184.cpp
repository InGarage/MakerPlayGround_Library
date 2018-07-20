#include "MP_ARDUINOALL_184.h"

MP_ARDUINOALL_184::MP_ARDUINOALL_184(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_184::init() 
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}

double MP_ARDUINOALL_184::getHumidity() 
{
    MP_Log::i(tag,(analogRead(pin)/1023.0)*100.0);
	return (analogRead(pin)/1023.0)*100.0;
}
