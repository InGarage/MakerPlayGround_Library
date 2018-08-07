#ifndef MP_ARDUINOALL_967_H
#define MP_ARDUINOALL_967_H

#include <Arduino.h>
class MP_ARDUINOALL_967
{
  public:
    MP_ARDUINOALL_967(uint8_t r, uint8_t g, uint8_t b,const String &tag);
    ~MP_ARDUINOALL_967(){};

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
