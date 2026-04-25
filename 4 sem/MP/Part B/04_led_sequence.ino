#define LED1 A0
#define LED2 A1
#define LED3 A2
#define LED4 A3

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  digitalWrite(LED1, HIGH);
  delay(1000);
  digitalWrite(LED1, LOW);

  digitalWrite(LED2, HIGH);
  delay(1000);
  digitalWrite(LED2, LOW);

  digitalWrite(LED3, HIGH);
  delay(1000);
  digitalWrite(LED3, LOW);

  digitalWrite(LED4, HIGH);
  delay(1000);
  digitalWrite(LED4, LOW);
}
