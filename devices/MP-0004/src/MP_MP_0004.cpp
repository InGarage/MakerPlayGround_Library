#include "MP_MP_0004.h"

MP_MP_0004::MP_MP_0004(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_MP_0004::init()
{
    pinMode(pin, OUTPUT);
}

void MP_MP_0004::on()
{
    digitalWrite(pin, HIGH);
}

void MP_MP_0004::off()
{
    digitalWrite(pin, LOW);
}
