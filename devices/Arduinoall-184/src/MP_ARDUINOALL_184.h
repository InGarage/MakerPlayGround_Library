#ifndef MP_ARDUINOALL_184_H
#define MP_ARDUINOALL_184_H

#include <Arduino.h>

class MP_ARDUINOALL_184
{
  public:
	MP_ARDUINOALL_184(uint8_t pin,const String &tag);

	double getHumidity();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif
