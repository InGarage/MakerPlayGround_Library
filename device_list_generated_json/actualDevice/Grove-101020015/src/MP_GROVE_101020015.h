#ifndef MP_GROVE_101020015_H
#define MP_GROVE_101020015_H

#include <Arduino.h>

class MP_GROVE_101020015
{
  public:
	MP_GROVE_101020015(uint8_t pin);

	double getTemperature();
	void init();

  private:
	uint8_t pin;

};

#endif
