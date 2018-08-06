#ifndef MP_ARDUINOALL_1533_H
#define MP_ARDUINOALL_1533_H

#include <Arduino.h>

class MP_ARDUINOALL_1533
{
  public:
	 MP_ARDUINOALL_1533(uint8_t echo ,uint8_t trig,const String &tag ) ;

	 double getDistance() ;
	 void init() ;

  private:
	  uint8_t trig;
	  uint8_t echo;
	  const String tag;
};

#endif
