int lectura = 0;
int pinled1 = 10;
int pinled2 = 11;
int pinalarma = 9;
void setup ()
{
  Serial.begin(9600);
}
void loop ()
{
  if (lectura <512){
 digitalWrite (pinled1, 1);
 digitalWrite (pinled2, 0);
 digitalWrite (pinalarma, 0);
  }
  else {
 digitalWrite(pinled1, 0);
 digitalWrite(pinled2, 1); 
 digitalWrite (pinalarma, 0);
  }
  if (lectura >512){
    digitalWrite (pinled1, 0);
    digitalWrite (pinled2, 0);
    digitalWrite (pinalarma, 1);
  }
  else {
   digitalWrite(pinled1, 1);
   digitalWrite(pinled2, 0); 
   digitalWrite (pinalarma, 0); 
  }
  lectura = analogRead(0);
 Serial.println(lectura);
 delay (1000);
}
