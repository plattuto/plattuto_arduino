const int ENA = 11;
const int ENB = 6;
const int IN1 = 10;
const int IN2 = 9;
const int IN3 = 8;
const int IN4 = 7;

int vel = 250;
int velGiro = 220;

void setup() {
  Serial.begin(115200);  // Iniciamos la comunicación serial

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char dato = Serial.read();
    if (dato == 'a') {
      forward();
    }
    if (dato == 't') {
      downcart();
    }
    if (dato == 'l') {
      leftcart();
    }
    if (dato == 'r') {
      rightcart();
    }
  }
}


void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}

void downcart() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, vel);
  analogWrite(ENB, vel);
}

void leftcart() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, vel);
  analogWrite(ENB, velGiro);
}

void rightcart() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, velGiro);
  analogWrite(ENB, vel);
}

void stopcart() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}