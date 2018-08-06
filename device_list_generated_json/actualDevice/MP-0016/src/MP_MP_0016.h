#ifndef MP_MP_0016_H
#define MP_MP_0016_H

#include <Arduino.h>
#include <Servo.h>
class MP_MP_0016
{
  public:
	MP_MP_0016(uint8_t pin,const String &tag);

	void moveto(int degree);
	void init();

  private:
	uint8_t pin;
	Servo myservo;
    const String tag;
};

#endif
