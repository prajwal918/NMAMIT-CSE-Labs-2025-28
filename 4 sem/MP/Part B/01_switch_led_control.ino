#define SWITCH1 D7
#define SWITCH2 D6
#define LED D8

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(SWITCH1, INPUT_PULLUP);
  pinMode(SWITCH2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(SWITCH1) == LOW) {
    digitalWrite(LED, HIGH);
  } else if (digitalRead(SWITCH2) == LOW) {
    digitalWrite(LED, LOW);
  }
}
