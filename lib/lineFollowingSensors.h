#ifndef LINEFOLLOWINGSENSORS_H_INCLUDED
#define LINEFOLLOWINGSENSORS_H_INCLUDED

#define R_SENSOR_R 3
#define R_SENSOR_M 4
#define R_SENSOR_L 2

#define L_SENSOR_R 8
#define L_SENSOR_M 9
#define L_SENSOR_L 5

#define CLOCKWISE 0
#define MIDDLE 1
#define COUNTERCLOCKWISE 2

const int whiteLevel = 600;
const int blackLevel = 850;

int readQD(int sensor);
int trackLine(void);

#endif // LINEFOLLOWINGSENSORS_H_INCLUDED
