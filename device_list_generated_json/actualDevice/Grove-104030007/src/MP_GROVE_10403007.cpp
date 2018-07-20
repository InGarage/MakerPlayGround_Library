#include "MP_GROVE_10403007.h"

MP_GROVE_10403007::MP_GROVE_10403007(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_GROVE_10403007::init()
{
    pinMode(this->pin, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_GROVE_10403007::on(int brightness)
{
    analogWrite(this->pin, map(brightness, 0, 100, 0, 255));
    MP_Log::i(tag,"On");
}

void MP_GROVE_10403007::off()
{
    digitalWrite(this->pin, LOW);
    MP_Log::i(tag,"Off");
}
