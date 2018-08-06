#include "MP_ARDUINOALL_967.h"

MP_ARDUINOALL_967::MP_ARDUINOALL_967(uint8_t r, uint8_t g, uint8_t b,const String &tag)
    : r(r), g(g), b(b),tag(tag)
{
}

void MP_ARDUINOALL_967::init()
{
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
}

void MP_ARDUINOALL_967::on(int red, int green, int blue, int brightness)
{
    red = 255 - (red*brightness)/100.0;
    green = 255 - (red*brightness)/100.0;
    blue = 255 - (red*brightness)/100.0;
    analogWrite(r, red);
    analogWrite(g, green);
    analogWrite(b, blue);
}

void MP_ARDUINOALL_967::off()
{
    digitalWrite(r, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
}
