#ifndef MP_MP_0018_H
#define MP_MP_0018_H

#include <Arduino.h>

class MP_MP_0018
{
  public:

	 MP_MP_0018(uint8_t echo ,uint8_t trig,const String &tag ) ;

	 double getDistance() ;
	 void init() ;

  private:
	  uint8_t trig;
	  uint8_t echo;
	  const String tag;
	 

};

#endif