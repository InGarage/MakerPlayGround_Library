#ifndef MP_MP_0011_H
#define MP_MP_0011_H

#include <Arduino.h>
#define MP_MP_0011_MAX_ARRAY 20

class MP_MP_0011
{
  public:
	MP_MP_0011(uint8_t pin,const String &tag);

	double getSoundLevel();
	void init();

  private:
	uint8_t pin;
	double normal;
	const String tag;
};

#endif
