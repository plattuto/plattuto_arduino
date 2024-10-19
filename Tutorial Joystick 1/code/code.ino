// Pines del joystick
const int pinX = A0;  // Eje X
const int pinY = A1;  // Eje Y
const int pinSW = 2;  // Botón del joystick

void setup() {
  Serial.begin(9600);
  
  pinMode(pinSW, INPUT_PULLUP);  // Botón como entrada
}

void loop() {
  // Leer los valores de los ejes X e Y (valores de 0 a 1023)
  int valorX = analogRead(pinX);
  int valorY = analogRead(pinY);
  
  // Leer el estado del botón (LOW si está presionado)
  int estadoBoton = digitalRead(pinSW);

  // Mostrar los valores en el monitor serial
  Serial.print("X: ");
  Serial.print(valorX);
  Serial.print(" | Y: ");
  Serial.print(valorY);
  Serial.print(" | Botón: ");
  if (estadoBoton == LOW) {
    Serial.println("Presionado");
  } else {
    Serial.println("No presionado");
  }

  delay(200);  // Pequeña pausa para no saturar el monitor serial
}
