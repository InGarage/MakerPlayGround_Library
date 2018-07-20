#include "MP_GROVE_103020005.h"

MP_GROVE_103020005::MP_GROVE_103020005(uint8_t pin)
    : pin(pin)
{
}

void MP_GROVE_103020005::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_GROVE_103020005::on()
{
    digitalWrite(this->pin, HIGH);
}

void MP_GROVE_103020005::off()
{
    digitalWrite(this->pin, LOW);
}
