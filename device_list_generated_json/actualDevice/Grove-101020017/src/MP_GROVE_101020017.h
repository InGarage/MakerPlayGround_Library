#ifndef MP_GROVE_101020017_H
#define MP_GROVE_101020017_H

#include <Arduino.h>
#include "MP_Log.h"
class MP_GROVE_101020017
{
  public:
	MP_GROVE_101020017(uint8_t pin,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif
