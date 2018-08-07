#ifndef MP_MP_0012_H
#define MP_MP_0012_H

#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"

class MP_MP_0012
{
public:
	MP_MP_0012(uint8_t tx, const String &tag);

	void init();
	void showValue(double num);
	void showData(double num);
	void off();

private:
	void sendInvalid();
    void showFloat(double num);
    void sendData(int num, uint8_t dot, bool negative);
    SendOnlySoftwareSerial serial;
    const String tag;
};

#endif
