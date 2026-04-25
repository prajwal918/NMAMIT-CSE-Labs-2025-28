#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  String text = " HELLO WORLD ";
  for (int i = 0; i < 16; i++) {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.print(text);
    delay(300);
  }
}
