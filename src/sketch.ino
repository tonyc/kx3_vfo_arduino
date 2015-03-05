#include "serLCD.h"

#define LCD_PIN 5
#define LED_PIN 13
#define BLINK_DELAY 75
#define BAUD_RATE 9600

#define LOOP_DELAY 50

serLCD lcd(LCD_PIN);

void setup() {
  delay(250);
  Serial.begin(BAUD_RATE);
  /*displayBanner();*/
}

String str = "";
char character;

void loop() {
  ledOff();
  Serial.write("FA;");

  // wait for FA00000000000;
  while (Serial.available() > 0) {
    character = Serial.read();

    if (character != ';') {
      str += character;
    } else {
      ledOn();

      displayFrequency(str);
      str = "";
    }
  }

  delay(LOOP_DELAY);
}

void displayBanner() {
  lcd.clear();
  lcd.setCursor(1,1);
  lcd.print("KX3");

  for (int i = 0; i < 4; i++) {
    blink();
  }
}

void displayFrequency(String msg) {
  lcd.setCursor(2, 7);
  lcd.print(formatFrequency(msg));
}

String formatFrequency(String vfo) {
  String freq = "";

  // e.g. convert '07' to '7'
  freq += String(vfo.substring(5, 7).toInt());

  freq += ".";
  freq += vfo.substring(7, 10);
  freq += ".";
  freq += vfo.substring(10, 13);

  return freq;
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

