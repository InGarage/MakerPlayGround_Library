#ifndef MP_GROVE_103020005_H
#define MP_GROVE_103020005_H

#include <Arduino.h>

class MP_GROVE_103020005
{
  public:
    MP_GROVE_103020005(uint8_t pin);

    void init();
    void on();
    void off();

  private:
    uint8_t pin;
};

#endif
