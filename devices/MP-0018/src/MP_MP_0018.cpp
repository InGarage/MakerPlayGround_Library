#include "MP_MP_0018.h"


MP_MP_0018::MP_MP_0018(uint8_t echo ,uint8_t trig,const String &tag )
  : trig(trig), echo(echo),tag(tag)
{
  
}

void MP_MP_0018::init()  
{	
	pinMode(this->trig,OUTPUT);
	pinMode(this->echo,INPUT);
}

double MP_MP_0018::getDistance() {	

    long cm=0 ;
    /* loop for filter an hardware error */
    do {
        digitalWrite(trig, LOW);
        delayMicroseconds(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);
        cm = pulseIn(echo, HIGH) / 29.0 / 2.0 ;
  	} while(cm>3000);
    return cm;

}
