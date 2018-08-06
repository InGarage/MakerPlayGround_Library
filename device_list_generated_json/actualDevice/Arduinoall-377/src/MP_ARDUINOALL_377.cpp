#include "MP_ARDUINOALL_377.h"

MP_ARDUINOALL_377::MP_ARDUINOALL_377(uint8_t pin,const String &tag)
	:pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_377::init()
{
}

bool MP_ARDUINOALL_377::isWet()
{
	return analogRead(pin) > 512;
}

bool MP_ARDUINOALL_377::isDry()
{
	return analogRead(pin) < 512;
}
