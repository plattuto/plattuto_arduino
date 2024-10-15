#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

int humedad = A0;
int intensidadLuz = A2;
int potPin = A1; // Pin del potenciómetro
int medidorBateria =A7;

int voltaje = 0;

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  dht.begin();
  pinMode(humedad, INPUT);
}

void loop() {
  int valHumedad = map(analogRead(humedad), 0, 1023, 100, 0);
  int valLuz = map(analogRead(intensidadLuz), 0, 850, 0, 100);
  int temp = 0, hum = 0;
  int valorVoltaje = (analogRead(medidorBateria) * 5)/1023;

  voltaje = map(valorVoltaje, 0, 5, 0, 100);

  temp = dht.readTemperature()-5;
  hum = dht.readHumidity()-5;

  int potValue = analogRead(potPin); // Leer valor del potenciómetro
  int brightness = map(potValue, 0, 1023, 0, 255); // Mapear valor a rango de 0-255

  analogWrite(3, brightness); // Ajustar la intensidad de la luz del LCD (usando pin PWM)

  lcd.print("HSU:");
  lcd.print(valHumedad);
  lcd.print("% ");
  lcd.print("L:");
  lcd.print(valLuz);
  lcd.print("%");
  lcd.setCursor(0, 1);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("HAI:");
  lcd.print(hum);
  lcd.print("%");
  lcd.print("M:");
  lcd.print(voltaje);
  lcd.print("%");

  Serial.print("Humedad de suelo: ");
  Serial.print(valHumedad);
  Serial.print(" ");
  Serial.print("Intensidad de luz: ");
  Serial.print(analogRead(intensidadLuz));
  Serial.print(" ");
  Serial.print("Temperatura C: ");
  Serial.print(temp);
  Serial.print(" ");
  Serial.print("Humedad aire: ");
  Serial.print(hum);
  Serial.print(" ");
  Serial.print(" ");
  Serial.print("Voltaje");
  Serial.println(voltaje);


  delay(5000);
  lcd.clear();
}