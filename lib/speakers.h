#ifndef SPEAKERS_H_INCLUDED
#define SPEAKERS_H_INCLUDED

#define FREQ_C 0
#define FREQ_D 1
#define FREQ_E 2
#define FREQ_F 3
#define FREQ_G 4
#define FREQ_A 5
#define FREQ_B 6

#define sinArraySize  255
#define x  (48000000/(8*(65535+1)))/255

const double freqs[] = {261.63, 293.66, 329.63, 349.23, 392.00, 440.00, 493.88};
const int pins[] = { 2, 14, 7, 8, 6, 20, 21, 5};

void op(int input);//currently not being used
void generateByte(int freq);
void speakerSetup();

#endif // SPEAKERS_H_INCLUDED
