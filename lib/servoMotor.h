#ifndef SERVOMOTOR_H_INCLUDED
#define SERVOMOTOR_H_INCLUDED

#define FAST_C 0
#define NORMAL_C 90
#define FAST_CC 180
#define NORMAL_CC 100
#define STOP 95

Servo ServoL;
Servo ServoR;

void goForward();
void stopMovement();
void turnRight();
void turnLeft();

#endif // SERVOMOTOR_H_INCLUDED
