#ifndef MP_GROVE_101020010_H
#define MP_GROVE_101020010_H

#include <Arduino.h>

class MP_GROVE_101020010
{
  public:
	MP_GROVE_101020010(uint8_t pin);

	void init();
	double getDistance() ;

  private:
	uint8_t pin;

};

#endif
