#include "MP_ARDUITRONICS_1705.h"

MP_ARDUITRONICS_1705::MP_ARDUITRONICS_1705(const String &tag)
	 :sensor(dht12(0x5c)),tag(tag)
{
}

void MP_ARDUITRONICS_1705::init() 
{
    dht::ReadStatus chk = sensor.read();
    if(chk != dht::OK)
    {
	    while(1) delay(20);
	}
}

double MP_ARDUITRONICS_1705::getTemperature()
{
    delay(50);
    dht::ReadStatus chk = sensor.read();
    if(chk == dht::OK)
    {
        double value = (double)sensor.getTemperature()/10.0;
        Serial.println(value);
	    return value;
	}
    return 9999999999;
}

double MP_ARDUITRONICS_1705::getHumidity() 
{
    delay(50);
    dht::ReadStatus chk = sensor.read();
    if(chk == dht::OK)
    {
        double value = (double)sensor.getHumidity()/10.0;
	    return value;
	}
    return 9999999999;
}
