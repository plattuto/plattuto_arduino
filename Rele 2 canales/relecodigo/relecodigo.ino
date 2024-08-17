// Definir los pines de los relés
const int rele1 = 7;
const int rele2 = 8;

void setup() {
  // Configurar los pines como salidas
  pinMode(rele1, OUTPUT);
  pinMode(rele2, OUTPUT);
  
  // Inicializar relés en estado apagado
  digitalWrite(rele1, HIGH);
  digitalWrite(rele2, HIGH);
}

void loop() {
  // Encender el primer relé (activar la electroválvula)
  digitalWrite(rele1, LOW); 
  delay(1000); // Mantener encendido por 1 segundo
  
  // Apagar el primer relé (desactivar la electroválvula)
  digitalWrite(rele1, HIGH);
  delay(1000); // Mantener apagado por 1 segundo
  
  // Encender el segundo relé (activar la segunda electroválvula)
  digitalWrite(rele2, LOW);
  delay(1000);
  
  // Apagar el segundo relé
  digitalWrite(rele2, HIGH);
  delay(1000);
}