#ifndef MP_ARDUINOALL_332_H
#define MP_ARDUINOALL_332_H

#include <Arduino.h>

class MP_ARDUINOALL_332
{
  public:
    MP_ARDUINOALL_332(uint8_t r, uint8_t g, uint8_t b,const String &tag);
    ~MP_ARDUINOALL_332(){};

    void init();
    void on(int red, int green, int blue, int brightness);
    void off();

  private:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    const String tag;
};

#endif
