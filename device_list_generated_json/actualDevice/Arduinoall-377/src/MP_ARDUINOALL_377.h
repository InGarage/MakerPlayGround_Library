#ifndef MP_ARDUINOALL_377_H
#define MP_ARDUINOALL_377_H

#include <Arduino.h>

class MP_ARDUINOALL_377
{
public:
	MP_ARDUINOALL_377(uint8_t pin,const String &tag) ;
	~MP_ARDUINOALL_377() {};

    void init();

	bool isWet();
	bool isDry();

private:
	uint8_t pin;
	const String tag;
};

#endif
