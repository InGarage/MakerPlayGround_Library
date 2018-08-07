#include "MP_ARDUINOALL_1015.h"

MP_ARDUINOALL_1015::MP_ARDUINOALL_1015(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_1015::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_ARDUINOALL_1015::beep()
{
    tone(this->pin, 2000);
    delay(100);
    noTone(this->pin);
}

void MP_ARDUINOALL_1015::play(double frequency, double duration)
{
    tone(this->pin, frequency);
    delay(duration * 1000);
    noTone(this->pin);
}
