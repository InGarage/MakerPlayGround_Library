#include "MP_MP_0008.h"

MP_MP_0008::MP_MP_0008(const String &tag)
    : imu(LSM6DS3(I2C_MODE, 0x6A)),tag(tag)
{
}

void MP_MP_0008::init()
{
    if (imu.begin() != IMU_SUCCESS)
    {
        //Serial.println("Can't detect LSM6DS3. Please check connection!!!");
        while(1);

    }
}

double MP_MP_0008::getAccel_X()
{
    return imu.readFloatAccelX();
}

double MP_MP_0008::getAccel_Y()
{
    return imu.readFloatAccelY();
}

double MP_MP_0008::getAccel_Z()
{
    return imu.readFloatAccelZ();
}

double MP_MP_0008::getAccel_Magnitude()
{
    return sqrt(imu.readFloatAccelX() * imu.readFloatAccelX()
        + imu.readFloatAccelY() * imu.readFloatAccelY()
        + imu.readFloatAccelZ() * imu.readFloatAccelZ());
}

double MP_MP_0008::getGyro_X()
{
    return imu.readFloatGyroX();
}

double MP_MP_0008::getGyro_Y()
{
    return imu.readFloatGyroY();
}

double MP_MP_0008::getGyro_Z()
{
    return imu.readFloatGyroZ();
}
