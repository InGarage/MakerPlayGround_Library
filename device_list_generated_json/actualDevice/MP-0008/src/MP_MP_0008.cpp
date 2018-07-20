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
        MP_Log::e(tag,"Can't detect LSM6DS3. Please check connection!!!");
        while(1);

    }
    MP_Log::i(tag,"Ready");
}

double MP_MP_0008::getAccel_X()
{
    MP_Log::i(tag, String("Accel X: ") + imu.readFloatAccelX());
    return imu.readFloatAccelX();
}

double MP_MP_0008::getAccel_Y()
{
    MP_Log::i(tag, String("Accel Y: ") + + imu.readFloatAccelY());
    return imu.readFloatAccelY();
}

double MP_MP_0008::getAccel_Z()
{
    MP_Log::i(tag,String("Accel Z: ") +imu.readFloatAccelZ());
    return imu.readFloatAccelZ();
}

double MP_MP_0008::getAccel_Magnitude()
{
    MP_Log::i(tag,String("Accel Magnitude: ") +sqrt(imu.readFloatAccelX() * imu.readFloatAccelX()
                          + imu.readFloatAccelY() * imu.readFloatAccelY()
                          + imu.readFloatAccelZ() * imu.readFloatAccelZ()));
    return sqrt(imu.readFloatAccelX() * imu.readFloatAccelX()
        + imu.readFloatAccelY() * imu.readFloatAccelY()
        + imu.readFloatAccelZ() * imu.readFloatAccelZ());
}

double MP_MP_0008::getGyro_X()
{
    MP_Log::i(tag,String("Gyro X: ") +imu.readFloatGyroX());
    return imu.readFloatGyroX();
}

double MP_MP_0008::getGyro_Y()
{
     MP_Log::i(tag,String("Gyro Y: ") +imu.readFloatGyroY());
    return imu.readFloatGyroY();
}

double MP_MP_0008::getGyro_Z()
{
     MP_Log::i(tag,String("Gyro Z: ") +imu.readFloatGyroZ());
    return imu.readFloatGyroZ();
}
