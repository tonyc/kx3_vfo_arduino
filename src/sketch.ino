#include "serLCD.h"

#define LCD_PIN 2
#define LED_PIN 13
#define BLINK_DELAY 75

/*serLCD lcd(LCD_PIN);*/

void setup() {
  delay(2000);

  Serial.begin(9600);
  Serial.println("hello world");

  for (int i = 0; i < 4; i++) {
    blink();
  }

  delay(1000);

}

String str = "";
char character;

void loop() {
  ledOn();

  delay(1000);
  Serial.print("fa;");

  // wait for FA00000000000;
  while (Serial.available() > 0) {
    character = Serial.read();

    if (character != ';') {
      str += character;
    } else {
      ledOff();

      Serial.println();
      Serial.println("------------");
      Serial.println(str);
      Serial.println("------------");

      str = "";

      delay(1000);
      break;
    }
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

