#include "speakers.h"

void op(int input){//not being used atm\

  for(int i = 0; i<8; i++){
    digitalWrite(pins[i], ((input>>i)&1) );
  }
}
//((input>>i)&1)
void generateByte(double freq){
  int i = floor(count*(double) (sinArraySize)/int_freq*freq);
  
  //Serial.print();
  
  
  if(i>=sinArraySize-1){
    cli();
    count = 0;
    i = floor(count*(double) (sinArraySize)/int_freq*freq);
    sei();
        
  } 
  //Serial.println(sinArray[i]);
  dac = sinArray[i];
  //op(sinArray[i]); 
}

void speakerSetup(){

  for(int i = 0; i<8; i++){
    pinMode(pins[i], OUTPUT);
  }
  
}

