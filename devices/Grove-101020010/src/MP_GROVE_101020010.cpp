#include "MP_GROVE_101020010.h"

MP_GROVE_101020010::MP_GROVE_101020010(uint8_t pin)
  : pin(pin)
{
  
}

void MP_GROVE_101020010::init() 
{
	pinMode(this->pin,INPUT);
}

double MP_GROVE_101020010::getDistance()
{
	double RangeInCentimeters = 0.0;
	pinMode(this->pin, OUTPUT);
	digitalWrite(this->pin, LOW);
	delayMicroseconds(2);
	digitalWrite(this->pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(this->pin,LOW);
	pinMode(this->pin,INPUT);
	double duration = pulseIn(this->pin,HIGH);
	RangeInCentimeters = duration/29/2;
    return RangeInCentimeters;
}
