#include "MP_ARDUINOALL_1533.h"

MP_ARDUINOALL_1533::MP_ARDUINOALL_1533(uint8_t echo ,uint8_t trig,const String &tag )
  : trig(trig) , echo(echo),tag(tag)
{
}

void MP_ARDUINOALL_1533::init()  
{	
	pinMode(this->trig,OUTPUT);
	pinMode(this->echo,INPUT);

}

double MP_ARDUINOALL_1533::getDistance() {	

	  long cm=0 ;
	  /* loop for filter an hardware error */
      do{
	      digitalWrite(trig, LOW);
	      delayMicroseconds(2);
	      digitalWrite(trig, HIGH);
	      delayMicroseconds(5);
	      digitalWrite(trig, LOW);
	      cm = pulseIn(echo, HIGH) / 29.0 /2.0 ;
  		}while(cm>3000);
      return cm;

}
