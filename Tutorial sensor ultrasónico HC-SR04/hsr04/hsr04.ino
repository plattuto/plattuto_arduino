#define trigPin 9
#define echoPin 10

void setup() {
  Serial.begin(9600);  // Inicializa la comunicación serial a 9600 baudios
  pinMode(trigPin, OUTPUT);  // Configura el pin trig como salida
  pinMode(echoPin, INPUT);  // Configura el pin echo como entrada
}

void loop() {
  long duration, distance;

  // Emite un pulso de 10 microsegundos en el pin trig
  digitalWrite(trigPin, LOW);  // Asegura que el pin trig esté bajo
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);  // Genera el pulso de 10 microsegundos
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo en microsegundos del pin echo
  duration = pulseIn(echoPin, HIGH);

  // Calcula la distancia en centímetros
  distance = (duration / 2) / 29.1;

  // Muestra la distancia por el monitor serial
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000);  // Espera 1 segundo antes de la siguiente medición
}