#include "MP_ARDUINOALL_377.h"

MP_ARDUINOALL_377::MP_ARDUINOALL_377(uint8_t pin,const String &tag)
	:pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_377::init()
{
    MP_Log::i(tag,"Ready");
}

bool MP_ARDUINOALL_377::isWet()
{
    MP_Log::i(tag,"Wet");
	return analogRead(pin) > 512;
}

bool MP_ARDUINOALL_377::isDry()
{
    MP_Log::i(tag,"Dry");
	return analogRead(pin) < 512;
}
