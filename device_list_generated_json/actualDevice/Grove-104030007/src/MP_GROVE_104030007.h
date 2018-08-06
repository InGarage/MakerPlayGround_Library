#ifndef MP_GROVE_104030007_H
#define MP_GROVE_104030007_H

#include <Arduino.h>
class MP_GROVE_104030007
{
  public:
    MP_GROVE_104030007(uint8_t pin,const String &tag);

    void init();
    void on(int brightness);
    void off();

  private:
    uint8_t pin;
    const String tag;
};

#endif
