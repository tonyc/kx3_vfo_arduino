#define LED_PIN 13

void setup()
{
  delay(2000);

  int i = 0;

  for (i; i < 3; i++) {
    blink();
  }

  ledOn();
  delay(2000);
}

void loop()
{
  ledOff();
  delay(125);
  ledOn();
  delay(125);
}

void ledOn() {
  digitalWrite(LED_PIN, HIGH);
}

void ledOff() {
  digitalWrite(LED_PIN, LOW);
}

void blink() {
  ledOn();
  delay(250);
  ledOff();
  delay(250);
}
