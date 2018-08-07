#ifndef MP_ARDUINOALL_1219_H
#define MP_ARDUINOALL_1219_H

#include <Arduino.h>
#include "TM1637Display.h"

class MP_ARDUINOALL_1219
{
  public:
	MP_ARDUINOALL_1219(uint8_t clk, uint8_t dio,const String &tag);
	~MP_ARDUINOALL_1219(){};

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
