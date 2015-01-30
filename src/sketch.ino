#define LED_PIN 13
#define BLINK_DELAY 75

#include "serLCD.h"

#define LCD_PIN 2

serLCD lcd(LCD_PIN);

void setup() {
  delay(1000);

  lcd.clear();

  delay(100);

  lcd.print("  MediBot 5000");

  delay(1000);

  for (int i = 0; i < 4; i++) {
    blink();
  }

  ledOn();

  delay(1000);

  ledOff();

  lcd.setCursor(2,1);
  lcd.print("millis: ");
}

void loop() {
  lcd.setCursor(2, 9);
  lcd.print(millis());
  delay(1000);
}

void ledOn() {
  led(HIGH);
}

void ledOff() {
  led(LOW);
}

void led(int state) {
  digitalWrite(LED_PIN, state);
}

void blink() {
  ledOn();
  delay(BLINK_DELAY);
  ledOff();
  delay(BLINK_DELAY);
}

