#ifndef MP_GROVE_10403007_H
#define MP_GROVE_10403007_H

#include <Arduino.h>
#include "MP_Log.h"
class MP_GROVE_10403007
{
  public:
    MP_GROVE_10403007(uint8_t pin,const String &tag);

    void init();
    void on(int brightness);
    void off();

  private:
    uint8_t pin;
    const String tag;
};

#endif
