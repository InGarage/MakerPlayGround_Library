#ifndef MP_MP_0003_H
#define MP_MP_0003_H

#include <Arduino.h>
class MP_MP_0003
{
  public:
    MP_MP_0003(uint8_t pin,const String &tag);
    MP_MP_0003(){};

    void init();
    void beep();
    void play(double frequency, double duration);

  private:
    uint8_t pin;
    const String tag;
};

#endif
