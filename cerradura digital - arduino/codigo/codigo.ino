#include <Servo.h>
#include <Keypad.h>
#include <stdlib.h>

Servo myServo;

const byte ROWS = 4; // 4 filas
const byte COLS = 4; // 4 columnas para un keypad 4x4
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};    // Conecta a los pines de las filas del keypad
byte colPins[COLS] = {6, 7, 8, 9};    // Conecta a los pines de las columnas del keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

String inputPassword = "";    // Almacena la clave ingresada
String correctPassword = "";  // Almacena la clave correcta generada
int attempts = 0;             // Contador de intentos fallidos

const int servoPin = 14;  // Nuevo pin para el servo (A0)
const int led1Pin = 10;   // Pin del LED 1
const int led2Pin = 11;   // Pin del LED 2
const int led3Pin = 12;   // Pin del LED 3
const int buttonPin = 13; // Pin del pulsador

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);    // Conecta el servo al nuevo pin (A0)
  myServo.write(0);            // Servo en la posición inicial
  
  pinMode(led1Pin, OUTPUT);    // Configura LED 1 como salida
  pinMode(led2Pin, OUTPUT);    // Configura LED 2 como salida
  pinMode(led3Pin, OUTPUT);    // Configura LED 3 como salida
  pinMode(buttonPin, INPUT_PULLUP); // Configura el pulsador con resistencia de pull-up

  generatePassword();               // Genera la clave inicial
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    if (key == '#') {
      if (inputPassword == correctPassword) {
        Serial.println("Clave Correcta");
        myServo.write(90); // Gira el servo a 90 grados (desbloquear)
        delay(3000);       // Mantiene el servo en posición por 3 segundos
        myServo.write(0);  // Regresa el servo a la posición inicial (bloquear)
        resetSystem();     // Resetea el sistema tras un desbloqueo exitoso
      } else {
        attempts++;
        Serial.println("Clave Incorrecta");
        if (attempts == 1) {
          digitalWrite(led1Pin, HIGH); // Enciende el LED 1
        } else if (attempts == 2) {
          digitalWrite(led2Pin, HIGH); // Enciende el LED 2
        } else if (attempts == 3) {
          digitalWrite(led3Pin, HIGH); // Enciende el LED 3
          Serial.println("Máximo de intentos alcanzado");
          resetSystem(); // Resetea el sistema si se alcanzó el máximo de intentos
        }
      }
      inputPassword = ""; // Resetea la clave ingresada
    } else if (key == '*') {
      inputPassword = ""; // Borra la clave ingresada
    } else {
      inputPassword += key; // Agrega el número ingresado a la clave
    }
  }

  if (digitalRead(buttonPin) == LOW) {
    delay(50); // Debouncing
    while (digitalRead(buttonPin) == LOW); // Espera hasta que se suelte el pulsador
    Serial.println("Generando nueva clave...");
    resetSystem(); // Genera una nueva clave cuando se presiona el pulsador
  }
}

void generatePassword() {
  correctPassword = "";
  for (int i = 0; i < 4; i++) {
    correctPassword += String(random(0, 10)); // Genera un dígito aleatorio de 0 a 9
  }
  Serial.print("Nueva Clave: ");
  Serial.println(correctPassword); // Muestra la clave generada en el monitor serie (quitar en producción)
}

void resetSystem() {
  digitalWrite(led1Pin, LOW); // Apaga el LED 1
  digitalWrite(led2Pin, LOW); // Apaga el LED 2
  digitalWrite(led3Pin, LOW); // Apaga el LED 3
  attempts = 0;            // Resetea el contador de intentos
  generatePassword();      // Genera una nueva clave
}
