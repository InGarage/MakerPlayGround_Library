#ifndef MP_GROVE_107020000_H
#define MP_GROVE_107020000_H

#include <Arduino.h>

class MP_GROVE_107020000
{
  public:
	MP_GROVE_107020000(uint8_t pin);
	~MP_GROVE_107020000(){};

	void init();
    void beep();
	
  private:
	uint8_t pin;
};

#endif
