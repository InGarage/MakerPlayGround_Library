#ifndef MP_ADAFRUIT_2652_H
#define MP_ADAFRUIT_2652_H

#include "Adafruit_Sensor.h"
#include "Adafruit_BME280.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#define SEALEVELPRESSURE_HPA (1013.25)

class MP_ADAFRUIT_2652
{
  public:
    MP_ADAFRUIT_2652(const String &tag);
	~MP_ADAFRUIT_2652() {};

/*	int pressure(char opt[], float treshold, uint8_t unit)  ;
	int attitude(char opt[], float treshold, uint8_t unit)  ;
	int humidity(char opt[], float treshold, uint8_t unit)  ;
	int checkTemp(char opt[], float treshold, uint8_t unit) ;*/
	double getPressure();
	double getAltitude();
	double getHumidity();
	double getTemperature();
	void init();

  private:
	Adafruit_BME280 bme;
	const String tag;
};

#endif
