#ifndef MP_MP_0007_H
#define MP_MP_0007_H

#include <Arduino.h>
class MP_MP_0007
{
  public:
	MP_MP_0007(uint8_t pin,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t pin;
	const String tag;
};

#endif
