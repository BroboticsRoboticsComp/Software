#ifndef GREYSCALESENSOR_H_INCLUDED
#define GREYSCALESENSOR_H_INCLUDED

#define GREYSCALE_PIN 15

#define SHADE_C 0
#define SHADE_D 1
#define SHADE_E 2
#define SHADE_F 3
#define SHADE_G 4
#define SHADE_A 5
#define SHADE_B 6
#define SHADE_C5 7

const int note[] = {1000, 660, 500, 350, 270, 200, 130, 90};

int readGS(void);

#endif // GREYSCALESENSOR_H_INCLUDED
