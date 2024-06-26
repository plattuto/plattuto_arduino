void setup() {
  //Inicializar puerto serie
  Serial.begin(9600);
}
void loop() {
  Serial.println("Hola mundo");
  delay(2000);
}