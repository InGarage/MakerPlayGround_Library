#include "MP_MP_0003.h"

MP_MP_0003::MP_MP_0003(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_MP_0003::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_MP_0003::beep()
{
    tone(this->pin, 2000);
    delay(100);
    noTone(this->pin);
}

void MP_MP_0003::play(double frequency, double duration)
{
    tone(this->pin, frequency);
    delay(duration * 1000);
    noTone(this->pin);
}
