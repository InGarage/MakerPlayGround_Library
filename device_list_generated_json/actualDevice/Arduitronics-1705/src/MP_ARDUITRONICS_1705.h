#ifndef MP_ARDUITRONICS_1705_H
#define MP_ARDUITRONICS_1705_H

#include "dht_dplasa.h"

#include <Arduino.h>
#include <Wire.h>

class MP_ARDUITRONICS_1705
{
  public:
	 MP_ARDUITRONICS_1705(const String &tag);
	 double getHumidity();
	 double getTemperature();
	 void init();

  private:
	 dht12 sensor;
	 const String tag;

};

#endif
