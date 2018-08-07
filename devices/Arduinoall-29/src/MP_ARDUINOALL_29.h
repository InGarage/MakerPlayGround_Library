#ifndef MP_ARDUINOALL_29_H
#define MP_ARDUINOALL_29_H

#include <Arduino.h>

class MP_ARDUINOALL_29
{
  public:
    MP_ARDUINOALL_29(uint8_t pin,const String &tag);

    int isDetected();
    int isNotDetected();
    void init();

  private:
    uint8_t pin;
    const String tag;
};

#endif
