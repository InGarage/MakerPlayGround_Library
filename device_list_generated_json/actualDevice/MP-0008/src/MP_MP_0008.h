#ifndef MP_MP_0008_H
#define MP_MP_0008_H

#include <Arduino.h>
#include "SparkFunLSM6DS3.h"
#include "Wire.h"

class MP_MP_0008
{
public:
		MP_MP_0008(const String &tag);

		void init();

		double getAccel_X();
		double getAccel_Y();
		double getAccel_Z();
		double getAccel_Magnitude();

		double getGyro_X();
		double getGyro_Y();
		double getGyro_Z();

private:
		LSM6DS3 imu;
		const String tag;
};

#endif
