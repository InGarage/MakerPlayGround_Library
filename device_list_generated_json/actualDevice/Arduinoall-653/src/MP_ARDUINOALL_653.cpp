#include "MP_ARDUINOALL_653.h"

MP_ARDUINOALL_653::MP_ARDUINOALL_653(int pin,const String &tag)
	 :sensor(DHT(pin, 11)), pin(pin),tag(tag)
{
}

void MP_ARDUINOALL_653::init() 
{
	sensor.begin();
	MP_Log::i(tag,"Ready");
}

double MP_ARDUINOALL_653::getTemperature()
{
    MP_Log::i(tag,sensor.readTemperature());
	return sensor.readTemperature() ;
}

double MP_ARDUINOALL_653::getHumidity() 
{
    MP_Log::i(tag,sensor.readHumidity());
	return sensor.readHumidity() ;
}
