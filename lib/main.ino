#include <math.h>
#include <Servo.h>

#include "servoMotor.h"
#include "lineFollowingSensors.h"
#include "speakers.h"

volatile int int_freq = 48000000/(8*(65535+1));

int divisions = 0;
byte sinArray[sinArraySize] = {0};

volatile byte dac = 0b00000000;
volatile int count = 0;

void setup() {
  Serial.begin(9600);

  setupServo();
  speakerSetup();
  pinMode(11,OUTPUT);
  //-------------//
  FTM0_SC = 0;
  FTM0_CNT = 0;
  FTM0_MOD = 0x0FFF;
  FTM0_SC = 0b01001000;
  //NVIC_SET_PRIORITY(IRQ_FTM0, 64);
  //NVIC_ENABLE_IRQ(IRQ_FTM0);
  //-------------//

  
  for(int i = 0; i<sinArraySize; i++){

    sinArray[i] = (byte) floor((sin((double)(i)/sinArraySize*2*PI)+1)*255/2.0/5.0);
    
  }
  
}
void loop() {
  //stopMovement(); 
  //Serial.println(dac);
  //generateByte(freqs[FREQ_C]);

  //LINE FOLLOWING CODE//
  
  if (trackLine() == CLOCKWISE) turnRight();
  if (trackLine() == COUNTERCLOCKWISE) turnLeft();
  if (trackLine() == MIDDLE) goForward();
  
  Serial.print("LEFT: ");
  Serial.println(readQD(R_SENSOR_L));

  Serial.print("Middle: ");
  Serial.println(readQD(R_SENSOR_M));

  Serial.print("Right: ");
  Serial.println(readQD(R_SENSOR_R));

  Serial.println();
  delay(1000);
}

void ftm0_isr(void) {
 
  count++;
  FTM0_SC |= (1 << 7);
  GPIOD_PDOR = dac/5;
    
}
