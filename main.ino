#include "MotorControl.h"

MotorControl motorControl(5, 6, 9, 10, 210);

void setup() {
  motorControl.setup();
}

void loop() {
  motorControl.update();
}

