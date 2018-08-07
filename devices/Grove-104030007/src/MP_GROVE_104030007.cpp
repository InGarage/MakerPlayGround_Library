#include "MP_GROVE_104030007.h"

MP_GROVE_104030007::MP_GROVE_104030007(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_GROVE_104030007::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_GROVE_104030007::on(int brightness)
{
    analogWrite(this->pin, map(brightness, 0, 100, 0, 255));
}

void MP_GROVE_104030007::off()
{
    digitalWrite(this->pin, LOW);
}
