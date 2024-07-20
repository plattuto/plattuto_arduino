#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27,16,2);  //

void setup() {

  lcd.init();


  lcd.backlight();
  lcd.print("Hola Mundo");
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print(millis()/1000);
  lcd.print(" Segundos");
  delay(100);
}