#include "MP_GROVE_107020000.h"

MP_GROVE_107020000::MP_GROVE_107020000(uint8_t pin)
    : pin(pin)
{
}

void MP_GROVE_107020000::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_GROVE_107020000::beep()
{
    digitalWrite(this->pin, HIGH);
    delay(100);
    digitalWrite(this->pin, LOW);
}
