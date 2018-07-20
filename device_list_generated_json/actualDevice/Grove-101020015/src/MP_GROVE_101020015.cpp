#include "MP_GROVE_101020015.h"

MP_GROVE_101020015::MP_GROVE_101020015(uint8_t pin)
  : pin(pin)
{
  
}

void MP_GROVE_101020015::init() 
{
	pinMode(this->pin,INPUT);
}

double MP_GROVE_101020015::getTemperature() 
{
	// return -40 + (analogRead(pin)/1023.0) * (125 - (-40));
    return analogRead(pin)/1023.0 * 125 - 40;
}
