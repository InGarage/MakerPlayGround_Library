#ifndef MP_ADAFRUIT_1063_H
#define MP_ADAFRUIT_1063_H

#include <Arduino.h>
#include "MP_Log.h"

class MP_ADAFRUIT_1063
{
  public:
    MP_ADAFRUIT_1063(uint8_t pin,const String &tag);
    ~MP_ADAFRUIT_1063() {};


    double getSoundLevel();
    void init();

  private:
    uint8_t pin;
    const String tag;
};

#endif
