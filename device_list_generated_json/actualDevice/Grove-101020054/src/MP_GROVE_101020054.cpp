#include "MP_GROVE_101020054.h"
void MP_GROVE_101020054::init()
{
    accel = Adafruit_ADXL345_Unified(12345);
    Serial.println("Accelerometer Test"); Serial.println("");
    
    /* Initialise the sensor */
    if(!accel.begin())
    {
        /* There was a problem detecting the ADXL345 ... check your connections */
        Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
        while(1);
    }

    /* Set the range to whatever is appropriate for your project */
    // accel.setRange(ADXL345_RANGE_16_G);
    // displaySetRange(ADXL345_RANGE_8_G);
    // displaySetRange(ADXL345_RANGE_4_G);
    accel.setRange(ADXL345_RANGE_2_G);
    
    /* Display some basic information on this sensor */
    // displaySensorDetails();
    
    // /* Display additional settings (outside the scope of sensor_t) */
    // displayDataRate();
    // displayRange();
}

double MP_GROVE_101020054::getAccel_Magnitude()
{
    sensors_event_t event;
    accel.getEvent(&event);
	double acc_x = event.acceleration.x;
	double acc_y = event.acceleration.y;
	double acc_z = event.acceleration.z;
	return sqrt(acc_x*acc_x + acc_y*acc_y + acc_z*acc_z);
}

double MP_GROVE_101020054::getAccel_X()
{
    sensors_event_t event;
    accel.getEvent(&event);
	return event.acceleration.x;
}

double MP_GROVE_101020054::getAccel_Y()
{
    sensors_event_t event;
    accel.getEvent(&event);
	return event.acceleration.y;
}

double MP_GROVE_101020054::getAccel_Z()
{
	sensors_event_t event;
    accel.getEvent(&event);
	return event.acceleration.z;
}
