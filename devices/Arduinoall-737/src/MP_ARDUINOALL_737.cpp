#include "MP_ARDUINOALL_737.h"

MP_ARDUINOALL_737::MP_ARDUINOALL_737(uint8_t inA, uint8_t inB,const String &tag)
    : inA(inA), inB(inB),tag(tag)
{
}

void MP_ARDUINOALL_737::init()
{
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
}

void MP_ARDUINOALL_737::on(char dir[], int speed)
{
    speed = map(speed, 0, 100, 0, 255);
    if (strcmp(dir, "Forward") == 0)
    {
        analogWrite(inA, speed);
        digitalWrite(inB, LOW);
    }
    else
    {
        digitalWrite(inA, LOW);
        analogWrite(inB, speed);
    }
}

void MP_ARDUINOALL_737::off()
{
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
}
