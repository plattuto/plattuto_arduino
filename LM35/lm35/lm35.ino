// Declaracion de variables globales
float tempC;
int pin = A5; 
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  // Con analogRead leemos el sensor - valores de 0 - 1023
  tempC = analogRead(pinLM35); 
   
  // Calculamos la temperatura con la fórmula
  tempC = (5.0 * tempC * 100.0)/1024.0; 
 
  Serial.print(tempC);
  Serial.println("");
  
  delay(1000); //Tiempo de espera entre cada lectura
}