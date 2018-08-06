#ifndef MP_MP_0001_H
#define MP_MP_0001_H

#include <Arduino.h>
class MP_MP_0001
{
  public:
    MP_MP_0001(uint8_t pin,const String &tag);

    void init();
    void on(int brightness);
    void off();

  private:
    uint8_t pin;
    const String tag;
};

#endif
