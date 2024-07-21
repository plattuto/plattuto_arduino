#include <Servo.h>

int base=3;
int centro=5;
int pinza=6;

Servo sbase, scentro, spinza;

char dato = ' ';

void setup()
{
  Serial.begin(9600);
  sbase.attach(base);
  scentro.attach(centro);
  spinza.attach(pinza);
  
  sbase.write(90);
  scentro.write(90);
  spinza.write(90);
  
  delay(3000);
}

void loop()
{
  
  if(Serial.available()>0){
    dato = Serial.read();
    
    if(dato == 'b'){
      	sbase.write(0);
  		delay(2000);
  		sbase.write(180);
  		delay(2000);
    }
    if(dato == 'c'){
      	scentro.write(0);
  		delay(2000);
  		scentro.write(180);
  		delay(2000);
    }
    if(dato == 'p'){
      	spinza.write(0);
  		delay(2000);
  		spinza.write(180);
  		delay(2000);
    }
    
  } 
}