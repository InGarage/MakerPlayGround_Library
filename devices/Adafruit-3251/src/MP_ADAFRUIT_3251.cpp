#include "MP_ADAFRUIT_3251.h"

MP_ADAFRUIT_3251::MP_ADAFRUIT_3251(const String &tag)
:   tag(tag)
{
}

void MP_ADAFRUIT_3251::init()
{
    sensor = Adafruit_Si7021();

    if (!sensor.begin()) {
        // Serial.println("Could not find a valid Si7021 sensor, check wiring!");
        while (1);
    }
}

double MP_ADAFRUIT_3251::getTemperature()
{
    return sensor.readTemperature();
}

double MP_ADAFRUIT_3251::getHumidity()
{
    return sensor.readHumidity();
}
