#include <arduino.h>

const int PIN_LED    = LED_BUILTIN;
const int PIN_BUTTON = 2;
const int PIN_PWM_LED = 9;
const int PIN_POT = A0;


void setup() {
  pinMode(PIN_LED, OUTPUT);
  digitalWrite(PIN_LED, LOW);

  pinMode(PIN_BUTTON, INPUT_PULLUP); // aktif-LOW
  pinMode(PIN_PWM_LED, OUTPUT);
  analogWrite(PIN_PWM_LED, 0);

  Serial.begin(115200);
  delay(50);
  Serial.println(F("If you press long, blink rate changes. Short press keeps LED on (then resume blink)."));
}

void loop() {
  unsigned long now = millis();

  // blink state
  static unsigned long lastBlink = 0;
  static bool ledState = false;
  static unsigned long blinkRate = 150; // ms

  // button state
  static bool lastPress = false;
  static unsigned long pressStart = 0;
  static bool longHandled = false;

  bool pressed = (digitalRead(PIN_BUTTON) == LOW);
  // first press
  if (pressed && !lastPress) {
    pressStart  = now;
    longHandled = false;
    digitalWrite(PIN_LED, HIGH);
    ledState = true;
    lastBlink = now;
  }

  const unsigned long LONG_PRESS_DURATION  = 3000;
  const unsigned long SHORT_MIN_DURATION   = 100;

  // long press
  if (pressed && !longHandled && (now - pressStart >= LONG_PRESS_DURATION)) {
    blinkRate += 200;
    if (blinkRate > 1000) blinkRate = 150;
    Serial.print(F("Blink rate changed to: "));
    Serial.print(blinkRate);
    Serial.println(F(" ms"));
    longHandled = true;
    lastBlink = now;
  }

  // release
  if (!pressed && lastPress) {
    unsigned long pressDuration = now - pressStart;
    if (!longHandled && pressDuration >= SHORT_MIN_DURATION) {
      Serial.println(F("Button short pressed, led on"));
    }
    lastBlink = now;
  }

  // normal blink
  if (!pressed && (now - lastBlink >= blinkRate)) {
    lastBlink = now;
    ledState = !ledState;
    digitalWrite(PIN_LED, ledState ? HIGH : LOW);
  }
  lastPress = pressed;

  // pot -> pwm task
  static unsigned long timePWM = 0;

  if(now-timePWM >= 200) {
    timePWM = now;
    int rawP = analogRead(PIN_POT);
    int pwm = map(rawP, 0, 1023, 0, 255);
    analogWrite(PIN_PWM_LED, pwm);
  }
}
