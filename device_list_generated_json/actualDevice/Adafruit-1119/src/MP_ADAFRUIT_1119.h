#ifndef MP_ADAFRUIT_1119_H
#define MP_ADAFRUIT_1119_H

#include <Arduino.h>

class MP_ADAFRUIT_1119
{
  public:
    MP_ADAFRUIT_1119(uint8_t pin,const String &tag);
    MP_ADAFRUIT_1119(){};

    void init();
    boolean isReleased();
    boolean isPressed();

  private:
    uint8_t pin;
    const String tag;
};

#endif
