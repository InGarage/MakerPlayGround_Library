#include "MP_ADAFRUIT_1032.h"
#define PI 3.14159265359

MP_ADAFRUIT_1032::MP_ADAFRUIT_1032(const String &tag)
:   tag(tag)
{
}


void MP_ADAFRUIT_1032::init()
{
  /* Enable auto-ranging */
  gyro.enableAutoRange(true);

  /* Initialise the sensor */
  if (!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    // Serial.println("Could not find a valid L3GD20 sensor, check wiring!");
    while (1);
  }
}

double MP_ADAFRUIT_1032::getGyro_X() 
{
    gyro.getEvent(&event);
    return event.gyro.x * PI;
}

double MP_ADAFRUIT_1032::getGyro_Y() 
{
    gyro.getEvent(&event);
    return event.gyro.y * PI;
}

double MP_ADAFRUIT_1032::getGyro_Z() 
{
    gyro.getEvent(&event);
    return event.gyro.z * PI;
}
