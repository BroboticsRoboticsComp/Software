#include <Servo.h>

#define FAST_C 0
#define NORMAL_C 45
#define FAST_CC 180
#define NORMAL_CC 135

Servo ServoL;
Servo ServoR;

int pos = 0;

void goForward(){
  ServoL.write(NORMAL_CC);
  ServoR.write(NORMAL_C);
}

void stopMovement(){
  ServoL.write(NORMAL_CC);
  ServoR.write(NORMAL_C);
  delay(200);
  ServoL.write(NORMAL_C);
  ServoR.write(NORMAL_CC);
  delay(200);
}

void turnRight(){
  ServoL.write(0);
}

void turnLeft(){
  ServoR.write(0);
}

void setup() {
  ServoL.attach(1);
  ServoR.attach(0);
  }

void loop() {
   goForward();
  //stopMovement();
}
