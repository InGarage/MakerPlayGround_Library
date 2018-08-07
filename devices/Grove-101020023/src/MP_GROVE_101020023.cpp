#include "MP_GROVE_101020023.h"

MP_GROVE_101020023::MP_GROVE_101020023(uint8_t pin)
	:pin(pin)
{
}

void MP_GROVE_101020023::init() 
{
	pinMode(this->pin, INPUT);
}

double MP_GROVE_101020023::getSoundLevel() 
{ 
    long sum = 0;
    for(int i=0; i<8; i++)
    {
        sum += analogRead(this->pin);
    }
    sum >>= 3;
    Serial.println(sum);
    delay(10);
	
	return 100.0*sum/1024.0;
}
