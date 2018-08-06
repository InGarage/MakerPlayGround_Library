#include "MP_ARDUITRONICS_220.h"

MP_ARDUITRONICS_220::MP_ARDUITRONICS_220(uint8_t clk, uint8_t dio,const String &tag)
	: display(TM1637Display(clk, dio)), data(0), brightness(7),tag(tag)
{
}

void MP_ARDUITRONICS_220::init()
{
}

void MP_ARDUITRONICS_220::showValue(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showFloat(value, true);
}

void MP_ARDUITRONICS_220::showData(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showNumberDec((int) value);
}

void MP_ARDUITRONICS_220::setBrightness(char c[])
{
	brightness = (int) c[0] - '0';
	display.setBrightness(brightness, true);
	display.showNumberDec((int) data);
}

void MP_ARDUITRONICS_220::off()
{
	uint8_t data[] = {0x0, 0x0, 0x0, 0x0};
	display.setBrightness(brightness, false);
	display.setSegments(data);
}
