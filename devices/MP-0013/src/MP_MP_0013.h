#ifndef MP_MP_0013_H
#define MP_MP_0013_H

#include <Arduino.h>

class MP_MP_0013
{
public:
    MP_MP_0013(uint8_t pin,const String &tag);

    void init();
    void on();
    void off();

private:
    uint8_t pin;
    const String tag;
};

#endif
