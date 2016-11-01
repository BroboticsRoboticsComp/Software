#include <Servo.h>

#include "servoMotor.h"

void setupServo() {
  ServoL.attach(0);
  ServoR.attach(1);
}

void goForward(){
  ServoL.write(NORMAL_CC);
  ServoR.write(NORMAL_C);
}

void goReverse(){
  ServoL.write(NORMAL_C);
  ServoR.write(NORMAL_CC);
}

void stopMovement(){
  if (ServoL.read() != STOP) ServoL.write(STOP);
  if (ServoR.read() != STOP) ServoR.write(STOP);
}

void turnRight(){
  ServoR.write(NORMAL_C);
  ServoL.write(FAST_CC);
}

void turnLeft(){
  ServoL.write(NORMAL_CC);
  ServoR.write(FAST_C);
}

void sonic(){
  ServoL.write(FAST_CC);
  ServoR.write(FAST_C);
}

/*
void loop() {
   goForward();
  //stopMovement();
}
*/
