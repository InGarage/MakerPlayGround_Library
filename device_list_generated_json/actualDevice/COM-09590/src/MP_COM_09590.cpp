#include "MP_COM_09590.h"

MP_COM_09590::MP_COM_09590(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_COM_09590::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_COM_09590::on(int brightness)
{
    analogWrite(this->pin, map(brightness, 0, 100, 0, 255));
}

void MP_COM_09590::off()
{
    digitalWrite(this->pin, LOW);
}
