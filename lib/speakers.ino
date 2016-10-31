#include "speakers.h"

void op(int input){//not being used atm\

  for(int i = 0; i<8; i++){
    digitalWrite(pins[i], ((input>>i)&1) );
  }
}
//((input>>i)&1)
void generateByte(int freq){
  int i = floor(count*255.0/int_freq*freq);
  dac = sinArray[i];
  op(sinArray[i]);
  if(i>=sinArraySize-1){
    count = 0;    
  }  
}

void speakerSetup(){

  for(int i = 0; i<8; i++){
    pinMode(pins[i], OUTPUT);
  }
  
}

