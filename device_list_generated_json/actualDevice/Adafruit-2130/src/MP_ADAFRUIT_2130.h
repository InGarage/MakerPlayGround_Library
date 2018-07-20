#ifndef MP_ADAFRUIT_2130_H
#define MP_ADAFRUIT_2130_H

/*
#include <SD.h>
#include <TMRpcm.h>
#include <SPI.h>
*/
#include <Arduino.h>

class MP_ADAFRUIT_2130
{
  public:
    // MP_ADAFRUIT_2130(uint8_t speakerPin) ;
    MP_ADAFRUIT_2130(uint8_t speakerPin);
    ~MP_ADAFRUIT_2130() {};

     /*void play(char file[], float vol)   ;
     void volUp()   ;
     void volDown()   ;
     void setVol(float vol)   ;
     void stop()   ; */

     void beep(float percentage, uint16_t dur);
     void tone(uint16_t hz, uint16_t dur);
     void init();

private:
    //uint8_t volLevel;
    //TMRpcm tmrpcm;
    uint8_t speakerPin;
    //uint8_t SDPin ;
};

#endif
