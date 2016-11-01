#include <math.h>
#include <Servo.h>

#include "servoMotor.h"
#include "lineFollowingSensors.h"
#include "speakers.h"
#include "greyScaleSensor.h"

volatile int int_freq = 48000000/(1*(4095+1));

byte sinArray[sinArraySize] = {0};

volatile byte dac = 0b00000000;
volatile int count = 0;

void setup() {
  Serial.begin(9600);

  setupServo();
  speakerSetup();
  
  pinMode(11,INPUT);
  
  //-------------//
  FTM0_SC = 0;
  FTM0_CNT = 0;
  FTM0_MOD = 0x0FFF;
  FTM0_SC = 0b01001000;
  
  //-------------//

  
  for(int i = 0; i<sinArraySize; i++){

    sinArray[i] = (byte) floor((sin((double)(i)/sinArraySize*2*PI)+1)*255/2.0/1);
    
  }
  NVIC_SET_PRIORITY(IRQ_FTM0, 64);
  NVIC_ENABLE_IRQ(IRQ_FTM0);
}

int cnt = 0;

void loop(){ 
  //GREYSCALE + PLAY MUSIC
  Serial.println(readGS());
  generateByte(freqs[readGS()]);
  
  //LINE FOLLOWING CODE//  
  
  if (trackLine() == CLOCKWISE) turnRight();
  if (trackLine() == COUNTERCLOCKWISE) turnLeft();
  if (trackLine() == MIDDLE) digitalRead(11) ? sonic() : goForward();
  
}
void ftm0_isr(void) {
 
  count++;
  
  FTM0_SC |= (1 << 7);
  GPIOD_PDOR = dac;
    
}
