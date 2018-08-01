#ifndef MP_MP_0017_H
#define MP_MP_0017_H

#include <Arduino.h>
#include "MP_Log.h"
#include "PinChangeInterrupt.h"

class MP_MP_0017
{
  public:
    MP_MP_0017(uint8_t pin, const String &tag);
    MP_MP_0017(){};

    void init();
    void update(unsigned long time);
    int isWaterFlow();
    double getFlow_Rate();
    double getTotal_Water_Amount();

  private:
    uint8_t pin;
    const String tag;

    double calibrationFactor;

    unsigned long oldTime;
    double flowRate;
    double flowMilliLitres;
    double totalMilliLitres;
    int flowChange;

    static volatile unsigned int pulseCount;
    static void interruptHandler();
};

#endif