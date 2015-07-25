#include <LiquidCrystal.h>

#define LED_PIN 13
#define BLINK_DELAY 75
#define BAUD_RATE 9600

#define LOOP_DELAY 50

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  delay(250);

  lcd.begin(16, 2);
  lcd.autoscroll();
  Serial.begin(BAUD_RATE);

  /*displayBanner();*/
}

String str = "";
char character;

void loop() {
  ledOff();

  //Serial.write("FA;");

  //// wait for FA00000000000;
  //while (Serial.available() > 0) {
  //  character = Serial.read();

  //  if (character != ';') {
  //    str += character;
  //  } else {
  //    ledOn();

  //    displayFrequency(str);
  //    str = "";
  //  }
  //}

  Serial.write("TB;");

  // wait for FA00000000000;
  while (Serial.available() > 0) {
    character = Serial.read();

    if (character != ';') {
      str += character;
    } else {
      ledOn();

      displayDecodeBuffer(str);
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
  lcd.setCursor(6, 1);
  lcd.print(formatFrequency(msg));
}

void displayDecodeBuffer(String msg) {
  //lcd.setCursor(16, 2);

  // TB000s;
  int messageLength = msg.substring(3, 5).toInt();

  if (messageLength > 0) {
    lcd.print(msg.substring(5, messageLength + 5));
  }

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

