#ifndef MP_MP_0004_H
#define MP_MP_0004_H

#include <Arduino.h>
#include "MP_Log.h"

class MP_MP_0004
{
public:
    MP_MP_0004(uint8_t pin,const String &tag);

    void init();
    void on();
    void off();

private:
    uint8_t pin;
    const String tag;
};

#endif
