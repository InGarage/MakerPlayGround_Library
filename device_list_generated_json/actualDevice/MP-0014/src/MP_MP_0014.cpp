#include "MP_MP_0014.h"

MP_MP_0014::MP_MP_0014(uint8_t data, uint8_t en,const String &tag)
  : data(data)
  , en(en)
  ,tag(tag)
{
}

void MP_MP_0014::init() 
{
	pinMode(data, INPUT);
    pinMode(en, OUTPUT);
}

double MP_MP_0014::getPercent()
{
    digitalWrite(en, HIGH);
    delay(5);
	double value = (analogRead(data) / 1023.0) * 100.0;
	digitalWrite(en, LOW);
    return value;
}
