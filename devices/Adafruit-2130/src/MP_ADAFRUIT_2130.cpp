#include "MP_ADAFRUIT_2130.h"

MP_ADAFRUIT_2130::MP_ADAFRUIT_2130( uint8_t speakerPin)
    :speakerPin(speakerPin)
{
}

void MP_ADAFRUIT_2130::init() 
{
    pinMode(speakerPin,OUTPUT);
}

/*
void MP_ADAFRUIT_2130::play(char file[], float vol) 
{

    if (vol < 12.5f)
        volLevel = 0;
    else if (vol < 25.0f)
        volLevel = 1;
    else if (vol < 37.5f)
        volLevel = 2;
    else if (vol < 50f)
        volLevel = 3;
    else if (vol < 62.5f)
        volLevel = 4;
    else if (vol < 75f)
        volLevel = 5;
    else if (vol < 87.5f)
        volLevel = 6;
    else if (vol <= 100.0f)
        volLevel = 7;
    

    tmrpcm.play(file);
    tmrpcm.setVolume(volLevel);
}

void MP_ADAFRUIT_2130::volUp() 
{
    tmrpcm.volume(1);
}
void MP_ADAFRUIT_2130::volDown() 
{
    tmrpcm.volume(0);

}

void MP_ADAFRUIT_2130::setVol(float vol) 
{
    if (vol < 12.5f)
        volLevel = 0;
    else if (vol < 25.0f)
        volLevel = 1;
    else if (vol < 37.5f)
        volLevel = 2;
    else if (vol < 50f)
        volLevel = 3;
    else if (vol < 62.5f)
        volLevel = 4;
    else if (vol < 75f)
        volLevel = 5;
    else if (vol < 87.5f)
        volLevel = 6;
    else if (vol <= 100.0f)
        volLevel = 7;

    tmrpcm.setVolume(volLevel);
}
void MP_ADAFRUIT_2130::stop() 
{
    tmrpcm.disable();
}
*/

void MP_ADAFRUIT_2130::beep(float percentage, uint16_t dur) 
{
    analogWrite(speakerPin, 255*(percentage/100.0));
    delay(dur);
}

void MP_ADAFRUIT_2130::tone(uint16_t hz, uint16_t dur) 
{
    tone(speakerPin, hz);
    delay(dur);
}
