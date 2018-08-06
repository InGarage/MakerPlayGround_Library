#ifndef MP_MP_0009_H
#define MP_MP_0009_H

#include <Arduino.h>
#include <Wire.h>
#include "SHTSensor.h"

class MP_MP_0009
{
public:
    MP_MP_0009(const String &tag);
    void init();
    double getTemperature();
    double getHumidity();

private:
    SHTSensor sht;
    const String tag;
};

#endif
