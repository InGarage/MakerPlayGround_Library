#include "MP_GROVE_101020011.h"

MP_GROVE_101020011::MP_GROVE_101020011(int pin,const String &tag)
	 :sensor(DHT(pin, 11)), pin(pin),tag(tag)
{
}

void MP_GROVE_101020011::init() 
{
	sensor.begin();
	MP_Log::i(tag,"Ready");
}

double MP_GROVE_101020011::getTemperature()
{
    MP_Log::i(tag,sensor.readTemperature());
	return sensor.readTemperature() ;
}

double MP_GROVE_101020011::getHumidity() 
{
    MP_Log::i(tag,sensor.readHumidity());
	return sensor.readHumidity() ;
}
