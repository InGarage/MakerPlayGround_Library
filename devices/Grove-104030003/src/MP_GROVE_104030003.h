#ifndef MP_GROVE_104030003_H
#define MP_GROVE_104030003_H

#include <Arduino.h>
#include "TM1637Display.h"

class MP_GROVE_104030003
{
  public:
	MP_GROVE_104030003(uint8_t clk, uint8_t dio,const String &tag);
	~MP_GROVE_104030003(){};

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
