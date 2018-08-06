#ifndef MP_MP_0014_H
#define MP_MP_0014_H

#include <Arduino.h>
class MP_MP_0014
{
  public:
	MP_MP_0014(uint8_t data, uint8_t en,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t data;
    uint8_t en;
    const String tag;

};

#endif
