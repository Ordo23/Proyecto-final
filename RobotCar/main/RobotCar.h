#ifndef RobotCar_h
#define RobotCar_h

#include <Arduino.h>
#include <NewPing.h>
#include <Servo.h>

class RobotCar {
public:
  RobotCar(int trigPin, int echoPin, int maxDistance, int servoPin,
           int motorPin1, int motorPin2, int motorPin3, int motorPin4);

  void setup();
  void loop();

private:
  NewPing sonar;
  Servo myservo;
  int motorPin1, motorPin2, motorPin3, motorPin4;
  int distance;
  int speedSet;
  boolean goesForward;

  void moveStop();
  void moveForward();
  void moveBackward();
  void turnRight();
  void turnLeft();
  int lookRight();
  int lookLeft();
  int readPing();
};

#endif

