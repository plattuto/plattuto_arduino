#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(6, 0);
  lcd.print("www.4lpes.com");
  lcd.setCursor(4, 1);
  lcd.print("Prueba de desplazamiento");
}

void loop() {

  lcd.scrollDisplayLeft(); 
  delay(500);
}