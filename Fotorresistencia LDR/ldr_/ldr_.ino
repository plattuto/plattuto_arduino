const int sensorPin = A0;
const int umbral = 500; 

void setup() {
  Serial.begin(9600); // Inicializar comunicación serial
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  Serial.print("Valor del sensor: ");
  Serial.println(sensorValue); 

  if (sensorValue < umbral) {
    Serial.println("Poca luz");
  } else {
    Serial.println("Mucha luz");
  }

  delay(1000);
}
