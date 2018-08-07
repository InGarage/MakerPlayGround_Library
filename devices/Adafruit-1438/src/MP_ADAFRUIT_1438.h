#ifndef MP_ADAFRUIT_1438_H
#define MP_ADAFRUIT_1438_H

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Arduino.h>

class MP_ADAFRUIT_1438
{
  public:
    MP_ADAFRUIT_1438(const String &tag) ;
    ~MP_ADAFRUIT_1438() {};
    void on(char dir[], uint8_t speed) ;
    void reverse() ;
    void set_speed(uint8_t speed) ;
    void off() ;
    void init() ;

  private:
    Adafruit_MotorShield AFMS =Adafruit_MotorShield();
    Adafruit_DCMotor *myMotor;
    uint8_t pin=0;
    const String tag;
};

#endif
