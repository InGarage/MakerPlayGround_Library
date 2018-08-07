#ifndef MP_ADAFRUIT_1032_H
#define MP_ADAFRUIT_1032_H

#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_L3GD20_U.h>

class MP_ADAFRUIT_1032
{
  public:
    MP_ADAFRUIT_1032(const String &tag);
    ~MP_ADAFRUIT_1032() {};

    double getGyro_X();
    double getGyro_Y();
    double getGyro_Z();
    void init();

  private:
    Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
    sensors_event_t event;
    const String tag;

};

#endif
