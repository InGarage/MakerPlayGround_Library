#ifndef MP_GROVE_101020011_H
#define MP_GROVE_101020011_H

#include "DHT.h"

#include <Arduino.h>

class MP_GROVE_101020011
{
  public:
	 MP_GROVE_101020011(int pin,const String &tag);
	 double getHumidity()  ;
	 double getTemperature()  ;
	 void init() ;

  private:
	 DHT sensor;
	 uint8_t pin;
	 const String tag;

};

#endif
