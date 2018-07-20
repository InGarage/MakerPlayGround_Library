#ifndef MP_GROVE_101020003_H
#define MP_GROVE_101020003_H

#include <Arduino.h>

class MP_GROVE_101020003
{
  public:
	MP_GROVE_101020003(uint8_t pin);
	~MP_GROVE_101020003(){};

	void init();
	boolean isReleased();
	boolean isPressed();
	
  private:
	uint8_t pin;
};

#endif
