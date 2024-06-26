int cont = 0;

void setup() {
  //Inicializar puerto serie
  Serial.begin(9600);
}
void loop() {
  cont++;
  //Enviar datos por el puerto serie
  Serial.println(cont);
  
  if(cont>=10){
    cont = 0;
  }
  delay(1000);
}