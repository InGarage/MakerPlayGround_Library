#ifndef MP_ARDUINOALL_34_H
#define MP_ARDUINOALL_34_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <MPU6050.h>

class MP_ARDUINOALL_34
{
  public:
    MP_ARDUINOALL_34(const String &tag);
    ~MP_ARDUINOALL_34(){};

    void init();

    double getAccel_X();
    double getAccel_Y();
    double getAccel_Z();
    double getAccel_Magnitude();

    double getGyro_X();
    double getGyro_Y();
    double getGyro_Z();

    bool checkDirection(char opt[]);

  private:
    MPU6050 accelgyro;
    const String tag;
};

#endif
