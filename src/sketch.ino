#include "serLCD.h"

#define LCD_PIN 2
#define LED_PIN 13
#define BLINK_DELAY 75

serLCD lcd(LCD_PIN);

void setup() {
  delay(500);

  Serial.begin(19200);
  lcd.clear();
  lcd.print("  MediBot 5000");

  for (int i = 0; i < 4; i++) {
    blink();
  }

  lcd.setCursor(2,1);
}

String vfo = "";
char character;

void loop() {
  Serial.print("fa;");
  delay(250);

  while (Serial.available() > 0) {
    character = Serial.read();
    lcd.listen();
    lcd.print(character);
    lcd.print(':');
  }

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

