#ifndef MP_ADAFRUIT_1334_H
#define MP_ADAFRUIT_1334_H
#define commonAnode true

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

class MP_ADAFRUIT_1334
{
  public:
    MP_ADAFRUIT_1334(const String &tag);
    ~MP_ADAFRUIT_1334() {};
    int isColor(char color[]);
    void init() ;
  private:
    const String tag;
};

#endif