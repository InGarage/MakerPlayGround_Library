#ifndef MP_GROVE_101020023_H
#define MP_GROVE_101020023_H

#include <Arduino.h>

class MP_GROVE_101020023
{
  public:
	  MP_GROVE_101020023(uint8_t pin);
	 ~MP_GROVE_101020023() {};

	 double getSoundLevel()  ;
	 void init() ;

  private:
	  uint8_t pin;
};

#endif
