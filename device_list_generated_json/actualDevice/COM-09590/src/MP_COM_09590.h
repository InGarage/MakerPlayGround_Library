#ifndef MP_COM_09590_H
#define MP_COM_09590_H

#include <Arduino.h>
class MP_COM_09590
{
  public:
    MP_COM_09590(uint8_t pin,const String &tag);

    void init();
    void on(int brightness);
    void off();

  private:
    uint8_t pin;
    const String tag;
};

#endif
