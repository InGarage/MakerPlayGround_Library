#include "MP_ARDUINOALL_1219.h"

MP_ARDUINOALL_1219::MP_ARDUINOALL_1219(uint8_t clk, uint8_t dio,const String &tag)
	: display(TM1637Display(clk, dio)), data(0), brightness(7),tag(tag)
{
}

void MP_ARDUINOALL_1219::init()
{
}

void MP_ARDUINOALL_1219::showValue(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showFloat(value);
}

void MP_ARDUINOALL_1219::showData(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showNumberDec((int) value);
}

void MP_ARDUINOALL_1219::setBrightness(char c[])
{
	brightness = (int) c[0] - '0';
	display.setBrightness(brightness, true);
	display.showNumberDec((int) data);
}

void MP_ARDUINOALL_1219::off()
{
	uint8_t data[] = {0x0, 0x0, 0x0, 0x0};
	display.setBrightness(brightness, false);
	display.setSegments(data);
}
