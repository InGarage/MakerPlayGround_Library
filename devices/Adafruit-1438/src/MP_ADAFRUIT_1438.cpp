#include "MP_ADAFRUIT_1438.h"

uint8_t direction;

MP_ADAFRUIT_1438::MP_ADAFRUIT_1438(const String &tag)
    : tag(tag)
{
    myMotor = AFMS.getMotor(1);
}


void MP_ADAFRUIT_1438::init() {
    AFMS.begin();
    direction = 1;
}

void MP_ADAFRUIT_1438::on(char dir[], uint8_t speed) {
    if(!strcmp(dir,"CW"))
        direction = 1 ;
    else if(!strcmp(dir,"CW"))
        direction = 2 ;

    myMotor->setSpeed(speed);
    if (direction == 1)
    {
        myMotor->run(FORWARD);
    }
    else if (direction == 2)
    {
        myMotor->run(BACKWARD);
    }
}

void MP_ADAFRUIT_1438::reverse() {
    if (direction == 1)
    {
        direction = 2;
        myMotor->run(BACKWARD);

    }
    else if (direction == 2)
    {
        direction = 1;
        myMotor->run(FORWARD);
    }
}

void MP_ADAFRUIT_1438::set_speed(uint8_t speed) {
    myMotor->setSpeed(speed);
}

void MP_ADAFRUIT_1438::off() {
    myMotor->setSpeed(0);
}
