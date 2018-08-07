#ifndef MP_ARDUINOALL_115_H
#define MP_ARDUINOALL_115_H

#include <Arduino.h>
#include <Wire.h>
class MP_ARDUINOALL_115
{
  public:
    MP_ARDUINOALL_115(uint8_t s0,uint8_t s1,uint8_t s2,uint8_t s3,uint8_t out,uint8_t LED,const String &tag) ;
    ~MP_ARDUINOALL_115() {};
    int isColor(char color[]);
    void init() ;

    private:
    uint8_t s0 ;
    uint8_t s1 ;
    uint8_t s2 ;
    uint8_t s3 ;
    uint8_t out ;
    uint8_t LED ;
    const String tag;
};

#endif
