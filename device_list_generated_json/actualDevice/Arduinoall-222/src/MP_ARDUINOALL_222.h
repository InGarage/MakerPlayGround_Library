#ifndef MP_ARDUINOALL_222_H
#define MP_ARDUINOALL_222_H

#include <Arduino.h>
class MP_ARDUINOALL_222
{
  public:
	MP_ARDUINOALL_222(uint8_t pin,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif
