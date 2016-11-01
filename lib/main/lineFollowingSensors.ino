#include "lineFollowingSensors.h"

const int whitelevl = 600;
const int blacklevl = 850;

int readQD(int sensor){
  int val = analogRead(sensor);  
  return val;
}

int trackLine(void){
  
  if ( (readQD(R_SENSOR_L)<whiteLevel && readQD(R_SENSOR_R)<whiteLevel && readQD(R_SENSOR_M)>blackLevel) &&
       (readQD(L_SENSOR_L)<whiteLevel && readQD(L_SENSOR_R)<whiteLevel && readQD(L_SENSOR_M)>blackLevel) ){
    return MIDDLE;
  }

  if ( (readQD(R_SENSOR_R)>blackLevel) ||
       (readQD(L_SENSOR_R)>blackLevel) ){
    return CLOCKWISE;
  }

  if ( (readQD(R_SENSOR_L)>blackLevel) ||
       (readQD(L_SENSOR_L)>blackLevel) ){
    return COUNTERCLOCKWISE;
  }

  return -1;
}

/*
void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  
  Serial.print("LEFT: ");
  Serial.println(readQD(L_SENSOR));

  Serial.print("Middle: ");
  Serial.println(readQD(M_SENSOR));

  Serial.print("Right: ");
  Serial.println(readQD(R_SENSOR));

  Serial.println();

  delay(2000);
}
*/
