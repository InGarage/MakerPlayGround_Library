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
        while (1);
    }
}

double MP_ADAFRUIT_2023::getTemperature() 
{
    return tmp007.readObjTempC() ;
}
