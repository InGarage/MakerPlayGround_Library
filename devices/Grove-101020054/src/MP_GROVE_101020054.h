#ifndef MP_GROVE_101020054_H
#define MP_GROVE_101020054_H

#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_ADXL345_U.h"

class MP_GROVE_101020054
{
  public:
	~MP_GROVE_101020054(){};

	void init();

	double getAccel_X();
	double getAccel_Y();
	double getAccel_Z();
	double getAccel_Magnitude();

  private:
	Adafruit_ADXL345_Unified accel;
};

#endif
