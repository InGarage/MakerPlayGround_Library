#ifndef MP_ARDUINOALL_737_H
#define MP_ARDUINOALL_737_H

#include <Arduino.h>

class MP_ARDUINOALL_737
{
  public:
    MP_ARDUINOALL_737(uint8_t inA, uint8_t inB,const String &tag);
    ~MP_ARDUINOALL_737(){};

    void init();
    void on(char dir[], int speed);
    // void reverse();
    // void set_speed(uint8_t speed);
    void off();

  private:
    uint8_t inA;
    uint8_t inB;
    const String tag;
};

#endif
