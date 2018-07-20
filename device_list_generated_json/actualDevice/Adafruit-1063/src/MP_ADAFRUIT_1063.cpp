#include "MP_ADAFRUIT_1063.h"

MP_ADAFRUIT_1063::MP_ADAFRUIT_1063(uint8_t pin,const String &tag)
    :pin(pin),tag(tag)
{

}

void MP_ADAFRUIT_1063::init() 
{
    pinMode(pin, INPUT);
    MP_Log::i(tag,"Ready");
}

double MP_ADAFRUIT_1063::getSoundLevel() 
{
    Serial.println(100.0*analogRead(pin)/1024.0);
    MP_Log::i(tag,100.0*analogRead(pin)/1024.0);
    return 100.0*analogRead(pin)/1024.0;
}
