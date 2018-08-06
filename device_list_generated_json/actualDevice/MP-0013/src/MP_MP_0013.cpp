#include "MP_MP_0013.h"

MP_MP_0013::MP_MP_0013(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_MP_0013::init()
{
    pinMode(pin, OUTPUT);
}

void MP_MP_0013::on()
{
    digitalWrite(pin, HIGH);
}

void MP_MP_0013::off()
{
    digitalWrite(pin, LOW);
}
