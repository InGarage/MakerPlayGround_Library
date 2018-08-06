#include "MP_GROVE_101020011.h"

MP_GROVE_101020011::MP_GROVE_101020011(int pin,const String &tag)
	 :sensor(DHT(pin, 11)), pin(pin),tag(tag)
{
}

void MP_GROVE_101020011::init() 
{
	sensor.begin();
}

double MP_GROVE_101020011::getTemperature()
{
	return sensor.readTemperature() ;
}

double MP_GROVE_101020011::getHumidity() 
{
	return sensor.readHumidity() ;
}
