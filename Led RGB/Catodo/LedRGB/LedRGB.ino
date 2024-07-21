int ledRojo = 6;
int ledVerde = 10;
int ledAzul = 11;

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
}

void loop() {
  digitalWrite(ledRojo, 255);
  digitalWrite(ledVerde, 0);
  digitalWrite(ledAzul, 0);
  delay(1500);

  digitalWrite(ledRojo, 0);
  digitalWrite(ledVerde, 255);
  digitalWrite(ledAzul, 0);
  delay(1500);

  digitalWrite(ledRojo, 0);
  digitalWrite(ledVerde, 0);
  digitalWrite(ledAzul, 255);
  delay(1500);
}