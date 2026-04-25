#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("MICROPROCESSOR");
  delay(1000);

  lcd.clear();

  lcd.setCursor(0, 1);
  lcd.print("HELLO WORLD");
  delay(1000);

  lcd.clear();
}
