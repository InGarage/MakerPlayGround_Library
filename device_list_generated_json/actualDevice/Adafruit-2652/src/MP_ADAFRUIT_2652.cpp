#include "MP_ADAFRUIT_2652.h"

MP_ADAFRUIT_2652::MP_ADAFRUIT_2652(const String &tag)
	: tag(tag)
{
}

void MP_ADAFRUIT_2652::init() {
	if (!bme.begin()) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}
}

double MP_ADAFRUIT_2652::getPressure() {
	return bme.readPressure() / 100.0 ;
}

double MP_ADAFRUIT_2652::getAltitude() {
	return bme.readAltitude(SEALEVELPRESSURE_HPA) ;
}

double MP_ADAFRUIT_2652::getHumidity() {
	return bme.readHumidity() ;
}

double MP_ADAFRUIT_2652::getTemperature() {
	return bme.readTemperature() ;
}
