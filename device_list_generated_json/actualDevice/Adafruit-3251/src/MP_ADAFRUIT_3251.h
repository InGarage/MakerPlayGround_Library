#ifndef MP_ADAFRUIT_3251_H
#define MP_ADAFRUIT_3251_H

#include "Adafruit_Si7021.h"
#include <Arduino.h>

class MP_ADAFRUIT_3251
{
  public:
    MP_ADAFRUIT_3251(const String &tag);
    ~MP_ADAFRUIT_3251() {};
    double getHumidity();
    double getTemperature();
    void init();

  private:
    Adafruit_Si7021 sensor;
    const String tag;
};

#endif
