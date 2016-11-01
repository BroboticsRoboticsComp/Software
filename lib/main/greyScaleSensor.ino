#include "greyScaleSensor.h"

int readGS(void){

  for(int i = 7; i>=0; i--){
    if(analogRead(GREYSCALE_PIN) < note[i]){
      return i;
    }
  }
  return 8;
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
