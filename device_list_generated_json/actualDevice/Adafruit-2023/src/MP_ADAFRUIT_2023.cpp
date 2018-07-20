#include "MP_ADAFRUIT_2023.h"

MP_ADAFRUIT_2023::MP_ADAFRUIT_2023(const String &tag)
:   tag(tag)
{
}

void MP_ADAFRUIT_2023::init() 
{
    if (!tmp007.begin()) 
    {
        Serial.println("Could not find a valid TMP007 sensor, check wiring!");
        MP_Log::e(tag,"Could not find a valid TMP007 sensor, check wiring!");
        while (1);
    }
    MP_Log::i(tag,"Ready");
}

double MP_ADAFRUIT_2023::getTemperature() 
{
    MP_Log::i(tag,tmp007.readObjTempC());
    return tmp007.readObjTempC() ;
}
