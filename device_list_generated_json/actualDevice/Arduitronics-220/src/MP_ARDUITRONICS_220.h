#ifndef MP_ARDUITRONICS_220_H
#define MP_ARDUITRONICS_220_H

#include <Arduino.h>
#include "TM1637Display.h"

class MP_ARDUITRONICS_220
{
  public:
	MP_ARDUITRONICS_220(uint8_t clk, uint8_t dio,const String &tag);
	~MP_ARDUITRONICS_220(){};

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
