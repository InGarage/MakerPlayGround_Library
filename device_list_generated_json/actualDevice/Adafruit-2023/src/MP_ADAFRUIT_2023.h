#ifndef MP_ADAFRUIT_2023_H
#define MP_ADAFRUIT_2023_H

#include <Wire.h>
#include "Adafruit_TMP007.h"
#include <Arduino.h>


class MP_ADAFRUIT_2023
{
  public:
    MP_ADAFRUIT_2023(const String &tag);
    ~MP_ADAFRUIT_2023() {};

    double getTemperature()  ;
    void init() ;

  private:
    Adafruit_TMP007 tmp007;
    const String tag;
};

#endif
