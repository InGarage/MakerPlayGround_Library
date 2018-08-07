#ifndef MP_ARDUINOALL_653_H
#define MP_ARDUINOALL_653_H

#include "DHT.h"

#include <Arduino.h>

class MP_ARDUINOALL_653
{
  public:
	 MP_ARDUINOALL_653(int pin,const String &tag);
	 double getHumidity()  ;
	 double getTemperature()  ;
	 void init() ;

  private:
	 DHT sensor;
	 uint8_t pin;
	 const String tag;

};

#endif
