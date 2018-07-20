#include "MP_MP_0001.h"

MP_MP_0001::MP_MP_0001(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_MP_0001::init()
{
    pinMode(this->pin, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_MP_0001::on(int brightness)
{
    analogWrite(this->pin, map(brightness, 0, 100, 0, 255));
    MP_Log::i(tag,"On");
}

void MP_MP_0001::off()
{
    digitalWrite(this->pin, LOW);
    MP_Log::i(tag,"Off");
}
