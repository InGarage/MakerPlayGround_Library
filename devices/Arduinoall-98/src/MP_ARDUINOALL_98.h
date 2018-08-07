#ifndef MP_ARDUINOALL_98_H
#define MP_ARDUINOALL_98_H

#include <Arduino.h>
class MP_ARDUINOALL_98
{
  public:
    MP_ARDUINOALL_98(uint8_t pin,const String &tag);

    double getPercent();
    void init();

  private:
    uint8_t pin;
    const String tag;
};

#endif
