#include "RobotCar.h"

RobotCar::RobotCar(int trigPin, int echoPin, int maxDistance, int servoPin,
                   int motor1, int motor2, int motor3, int motor4)
  : sonar(trigPin, echoPin, maxDistance), myservo(), motorPin1(motor1),
    motorPin2(motor2), motorPin3(motor3), motorPin4(motor4) {
}

void RobotCar::setup() {
  myservo.attach(3);
  myservo.write(115);
  delay(2000);

  for (int i = 0; i < 4; ++i) {
    distance = this->readPing();
    delay(100);
  }
}

void RobotCar::loop() {
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=25)                //SE ACTIVA EL SENSOR ULTRASONICO CUANDO DETECTA OBSTACULOS A MENOS DE 25CM.
 {
  moveStop();                   
  delay(200);                   
  moveBackward();              //EL CARRITO SE DETIENE Y SE VA HACIA ATRAS POR 800 MILISEGUNDOS.
  delay(800);                      
  
  moveStop();
  delay(200);
  distanceR = lookRight();       
  delay(200);
  distanceL = lookLeft();         
  delay(200);

  if(distanceR>=distanceL){
    turnRight();           
    moveStop();
  } else {
    turnLeft();            
    moveStop();
  } 
 }else{
  moveForward();         
 }
 distance = readPing();
}

int RobotCar::lookRight() {
  myservo.write(50);
  delay(500);
  int distance = this->readPing();
  delay(100);
  myservo.write(115);
  return distance;
}

int RobotCar::lookLeft() {
  myservo.write(170);
  delay(500);
  int distance = this->readPing();
  delay(100);
  myservo.write(115);
  return distance;
}

int RobotCar::readPing() {
  delay(70);
  int cm = this->sonar.ping_cm();
  if (cm == 0) {
    cm = 250;
  }
  return cm;
}

void RobotCar::moveStop() {
  analogWrite(this->motorPin1, 0);
  analogWrite(this->motorPin2, 0);
  analogWrite(this->motorPin3, 0);
  analogWrite(this->motorPin4, 0);
}

void RobotCar::moveForward() {
  analogWrite(this->motorPin1, 180);
  analogWrite(this->motorPin2, 0);
  analogWrite(this->motorPin3, 180);
  analogWrite(this->motorPin4, 0);
}

void RobotCar::moveBackward() {
  analogWrite(this->motorPin1, 0);
  analogWrite(this->motorPin2, 180);
  analogWrite(this->motorPin3, 0);
  analogWrite(this->motorPin4, 180);
}

void RobotCar::turnRight() {
  analogWrite(this->motorPin1, 180);
  analogWrite(this->motorPin2, 0);
  analogWrite(this->motorPin3, 0);
  analogWrite(this->motorPin4, 180);
  delay(300);
  this->moveForward();
}

void RobotCar::turnLeft() {
  analogWrite(this->motorPin1, 0);
  analogWrite(this->motorPin2, 180);
  analogWrite(this->motorPin3, 180);
  analogWrite(this->motorPin4, 0);
  delay(300);
  this->moveForward();
}

