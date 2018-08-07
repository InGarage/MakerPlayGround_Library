#include "MP_MP_0009.h"

MP_MP_0009::MP_MP_0009(const String &tag)
	: tag(tag)
{
}

void MP_MP_0009::init()
{
    Wire.begin();
    sht.init();
}

double MP_MP_0009::getTemperature()
{
    sht.readSample();
    return sht.getTemperature();
}

double MP_MP_0009::getHumidity()
{
    sht.readSample();
    return sht.getHumidity();
}
