#ifndef MP_GROVE_101020020_H
#define MP_GROVE_101020020_H

#include <Arduino.h>

class MP_GROVE_101020020
{
  public:
    MP_GROVE_101020020(uint8_t pin);

    void init();
    int isDetected();
    int isNotDetected();

  private:
    uint8_t pin;
};

#endif
