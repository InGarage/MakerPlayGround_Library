#ifndef MP_MP_0005_H
#define MP_MP_0005_H

#include <Arduino.h>
class MP_MP_0005
{
  public:
	MP_MP_0005(uint8_t pin,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif
