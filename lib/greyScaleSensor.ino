#include "greyScaleSensor.h"

int readGS(void){

  for(int i = 0; i<7; i++){
    if(digitalRead(GREYSCALE_PIN) < note[i]){
      return i;
    }
  }

}

void greyScaleSetup(){
  
   pinMode(GREYSCALE_PIN, INPUT);
  
}
/*
void setup()
{
 Serial.begin(9600);
 pinMode(grayscalePin,INPUT);
 Serial.println("Smart Grayscale sensor:");
}
void loop()
{
  Serial.print("Grayscale:");
  if(digitalRead(grayscalePin))
  {
    Serial.println("White detected");
  }
  else
  {
    Serial.println("Black detected");
  }
  
  delay(500);
}
*/
