#include "MP_ARDUINOALL_653.h"

MP_ARDUINOALL_653::MP_ARDUINOALL_653(int pin,const String &tag)
	 :sensor(DHT(pin, 11)), pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_653::init() 
{
	sensor.begin();
}

double MP_ARDUINOALL_653::getTemperature()
{
	return sensor.readTemperature() ;
}

double MP_ARDUINOALL_653::getHumidity() 
{
	return sensor.readHumidity() ;
}
