#include "MP_ADAFRUIT_2652.h"

MP_ADAFRUIT_2652::MP_ADAFRUIT_2652(const String &tag)
	: tag(tag)
{
}

void MP_ADAFRUIT_2652::init() {
	if (!bme.begin()) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		MP_Log::e(tag,"Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}
	MP_Log::i(tag,"Ready");
}

double MP_ADAFRUIT_2652::getPressure() {
    MP_Log::i(tag,bme.readPressure() / 100.0);
	return bme.readPressure() / 100.0 ;
}

double MP_ADAFRUIT_2652::getAltitude() {
    MP_Log::i(tag,bme.readAltitude(SEALEVELPRESSURE_HPA));
	return bme.readAltitude(SEALEVELPRESSURE_HPA) ;
}

double MP_ADAFRUIT_2652::getHumidity() {
    MP_Log::i(tag,bme.readHumidity());
	return bme.readHumidity() ;
}

double MP_ADAFRUIT_2652::getTemperature() {
    MP_Log::i(tag,bme.readTemperature());
	return bme.readTemperature() ;
}
