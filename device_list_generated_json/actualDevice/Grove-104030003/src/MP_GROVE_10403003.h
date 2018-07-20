#ifndef MP_GROVE_10403003_H
#define MP_GROVE_10403003_H

#include <Arduino.h>
#include "TM1637Display.h"
#include "MP_Log.h"

class MP_GROVE_10403003
{
  public:
	MP_GROVE_10403003(uint8_t clk, uint8_t dio,const String &tag);
	~MP_GROVE_10403003(){};

	void init();
	void showValue(double value);
	void showData(double value);
	void setBrightness(char c[]);
	void off();

  private:
	int data;
	int brightness;
	TM1637Display display;
	const String tag;
};

#endif
