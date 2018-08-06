#include "MP_MP_0016.h"

MP_MP_0016::MP_MP_0016(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
}

void MP_MP_0016::init()
{
	myservo.attach(pin);
}

void MP_MP_0016::moveto(int degree)
{
	myservo.write(degree);
}
