#include "MP_MP_0004.h"

MP_MP_0004::MP_MP_0004(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_MP_0004::init()
{
    pinMode(pin, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_MP_0004::on()
{
    digitalWrite(pin, HIGH);
    MP_Log::i(tag,"On");
}

void MP_MP_0004::off()
{
    digitalWrite(pin, LOW);
    MP_Log::i(tag,"Off");
}
