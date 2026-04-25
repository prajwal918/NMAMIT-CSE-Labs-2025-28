#include <Stepper.h>

#define SWT1 D7
#define SWT2 D6

Stepper myStep(2048, D2, D4, D3, D5);

void setup() {
  myStep.setSpeed(10);
  pinMode(SWT1, INPUT_PULLUP);
  pinMode(SWT2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(SWT1) == LOW) {
    myStep.step(2048);   // forward 1 revolution
  }

  if (digitalRead(SWT2) == LOW) {
    myStep.step(-2048);  // reverse 1 revolution
  }
}
