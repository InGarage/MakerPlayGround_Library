#ifndef MP_MP_0006_H
#define MP_MP_0006_H

#include <Arduino.h>

class MP_MP_0006
{
  public:
	MP_MP_0006(uint8_t pin,const String &tag);
	MP_MP_0006(){};

	void init();
	boolean isReleased();
	boolean isPressed();
	
  private:
	uint8_t pin;
	const String tag;
};

#endif
