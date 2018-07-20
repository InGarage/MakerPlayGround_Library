#include "MP_GROVE_10403003.h"

MP_GROVE_10403003::MP_GROVE_10403003(uint8_t clk, uint8_t dio,const String &tag)
	: display(TM1637Display(clk, dio)), data(0), brightness(7),tag(tag)
{
}

void MP_GROVE_10403003::init()
{
    MP_Log::i(tag,"Ready");
}

void MP_GROVE_10403003::showValue(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showFloat(value, true);
	MP_Log::i(tag,String("Show Value: ") + value);
}

void MP_GROVE_10403003::showData(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showNumberDec((int) value);
	MP_Log::i(tag,String("Show Data: ") + value);
}

void MP_GROVE_10403003::setBrightness(char c[])
{
	brightness = (int) c[0] - '0';
	display.setBrightness(brightness, true);
	display.showNumberDec((int) data);
}

void MP_GROVE_10403003::off()
{
	uint8_t data[] = {0x0, 0x0, 0x0, 0x0};
	display.setBrightness(brightness, false);
	display.setSegments(data);
	MP_Log::i(tag,"Off");
}
