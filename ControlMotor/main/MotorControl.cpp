#include "MotorControl.h"

MotorControl::MotorControl(int izqAPin, int izqBPin, int derAPin, int derBPin, int velocidad)
  : izqA(izqAPin), izqB(izqBPin), derA(derAPin), derB(derBPin), velocidad(velocidad), estado('c') {
}

void MotorControl::setup() {
  Serial.begin(9600);
  pinMode(derA, OUTPUT);
  pinMode(derB, OUTPUT);
  pinMode(izqA, OUTPUT);
  pinMode(izqB, OUTPUT);
}

void MotorControl::update() {
  processBluetooth();
}

void MotorControl::moveForward() {
  analogWrite(derB, 0);
  analogWrite(izqB, 0);
  analogWrite(derA, velocidad);
  analogWrite(izqA, velocidad);
}

void MotorControl::turnRight() {
  analogWrite(derB, 0);
  analogWrite(izqB, 0);
  analogWrite(izqA, 0);
  analogWrite(derA, velocidad);
}

void MotorControl::turnLeft() {
  analogWrite(derB, 0);
  analogWrite(izqB, 0);
  analogWrite(derA, 0);
  analogWrite(izqA, velocidad);
}

void MotorControl::stopMotor() {
  analogWrite(derB, 0);
  analogWrite(izqB, 0);
  analogWrite(derA, 0);
  analogWrite(izqA, 0);
}

void MotorControl::reverseMotor() {
  analogWrite(derA, 0);
  analogWrite(izqA, 0);
  analogWrite(derB, velocidad);
  analogWrite(izqB, velocidad);
}

void MotorControl::processBluetooth() {
  if (Serial.available() > 0) {
    estado = Serial.read();
  }

  switch (estado) {
    case 'a':
      moveForward();
      break;

    case 'b':
      turnLeft();
      break;

    case 'c':
      stopMotor();
      break;

    case 'd':
      turnRight();
      break;

    case 'e':
      reverseMotor();
      break;

    case 'g':
      stopMotor();
      break;
  }
}

