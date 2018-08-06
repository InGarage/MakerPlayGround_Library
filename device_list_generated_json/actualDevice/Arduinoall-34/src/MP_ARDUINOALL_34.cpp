#include "MP_ARDUINOALL_34.h"
#define ERROR 10.0f
#define GRAVITY 9.81

MP_ARDUINOALL_34::MP_ARDUINOALL_34(const String &tag)
    : tag(tag)
{
}

void MP_ARDUINOALL_34::init()
{
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
    Fastwire::setup(400, true);
#endif

    accelgyro.initialize();
    if (!accelgyro.testConnection())
    {
        /* There was a problem detecting the LSM303 ... check your connections */
        while (1);
    }
}

double MP_ARDUINOALL_34::getAccel_Magnitude()
{
    // the default range is +-2g and the sensor is 16 bits
    double acc_x = (accelgyro.getAccelerationX() / 16384.0);
    double acc_y = (accelgyro.getAccelerationY() / 16384.0);
    double acc_z = (accelgyro.getAccelerationZ() / 16384.0);
    return sqrt(acc_x*acc_x + acc_y*acc_y + acc_z*acc_z) * GRAVITY;
}

double MP_ARDUINOALL_34::getAccel_X()
{
    // the default range is +-2g and the sensor is 16 bits
    return (accelgyro.getAccelerationX() / 16384.0) * GRAVITY;
}

double MP_ARDUINOALL_34::getAccel_Y()
{
    // the default range is +-2g and the sensor is 16 bits
    return (accelgyro.getAccelerationY() / 16384.0) * GRAVITY;
}

double MP_ARDUINOALL_34::getAccel_Z()
{
    // the default range is +-2g and the sensor is 16 bits
    return (accelgyro.getAccelerationZ() / 16384.0) * GRAVITY;
}

double MP_ARDUINOALL_34::getGyro_X()
{
    // the default range is +-250degree/sec and the sensor is 16 bits
    return accelgyro.getRotationX() / 32768.0 * 250.0;
}

double MP_ARDUINOALL_34::getGyro_Y()
{
    // the default range is +-250degree/sec and the sensor is 16 bits
    return accelgyro.getRotationY() / 32768.0 * 250.0;
}

double MP_ARDUINOALL_34::getGyro_Z()
{
    // the default range is +-250degree/sec and the sensor is 16 bits
    return accelgyro.getRotationZ() / 32768.0 * 250.0;
}
