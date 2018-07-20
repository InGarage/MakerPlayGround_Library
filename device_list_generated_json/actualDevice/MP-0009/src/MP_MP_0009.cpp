#include "MP_MP_0009.h"

MP_MP_0009::MP_MP_0009(const String &tag)
	: tag(tag)
{
}

void MP_MP_0009::init()
{
    Wire.begin();
    sht.init();
    MP_Log::i(tag,"Ready");
}

double MP_MP_0009::getTemperature()
{
    sht.readSample();
    MP_Log::i(tag,sht.getTemperature());
    return sht.getTemperature();
}

double MP_MP_0009::getHumidity()
{
    sht.readSample();
    MP_Log::i(tag,sht.getHumidity());
    return sht.getHumidity();
}
