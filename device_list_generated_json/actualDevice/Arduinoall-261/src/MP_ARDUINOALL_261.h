#ifndef MP_ARDUINOALL_261_H
#define MP_ARDUINOALL_261_H

#include <Arduino.h>
class MP_ARDUINOALL_261
{
  public:
	MP_ARDUINOALL_261(uint8_t pin,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif
