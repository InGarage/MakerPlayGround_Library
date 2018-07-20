#include "MP_MP_0013.h"

MP_MP_0013::MP_MP_0013(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_MP_0013::init()
{
    pinMode(pin, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_MP_0013::on()
{
    digitalWrite(pin, HIGH);
    MP_Log::i(tag,"On");
}

void MP_MP_0013::off()
{
    digitalWrite(pin, LOW);
    MP_Log::i(tag,"Off");
}
