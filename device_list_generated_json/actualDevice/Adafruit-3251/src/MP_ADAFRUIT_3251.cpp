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
        MP_Log::e(tag,"Could not find a valid Si7021 sensor, check wiring!");
        while (1);
    }
    MP_Log::i(tag,"Ready");
}

double MP_ADAFRUIT_3251::getTemperature()
{
    MP_Log::i(tag,sensor.readTemperature());
    return sensor.readTemperature();
}

double MP_ADAFRUIT_3251::getHumidity()
{
    MP_Log::i(tag,sensor.readHumidity());
    return sensor.readHumidity();
}
