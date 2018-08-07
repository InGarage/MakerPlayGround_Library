#ifndef MP_ARDUINOALL_1015_H
#define MP_ARDUINOALL_1015_H

#include <Arduino.h>
class MP_ARDUINOALL_1015
{
  public:
    MP_ARDUINOALL_1015(uint8_t pin,const String &tag);
    MP_ARDUINOALL_1015(){};

    void init();
    void beep();
    void play(double frequency, double duration);

  private:
    uint8_t pin;
    const String tag;
};

#endif
