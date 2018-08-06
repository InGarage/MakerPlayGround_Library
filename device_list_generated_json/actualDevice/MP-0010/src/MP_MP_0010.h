#ifndef MP_MP_0010_H
#define MP_MP_0010_H

#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_APDS9960.h"

class MP_MP_0010
{
public:
    MP_MP_0010(const String &tag);

    void init();
    double getDistance();
    bool isGestureDetected(char c[]);
    bool isGestureNotDetected();

private:
    SparkFun_APDS9960 apds;
    const String tag;
};

#endif
