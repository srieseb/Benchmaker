#define motor1_A 11
#define motor1_B 10
#define motor1_Speed 9

#include "functions.h"


 


void setup(){
  pinMode(motor1_A,OUTPUT);
  pinMode(motor1_B,OUTPUT);

  Serial.begin(9600);
}



void loop() {
  // Serial Request: 1 to 255 is forward turning motor with the according speed; Analog backwards from -1 to -255; 0 = Stop
  if (Serial.available())
  {
    int speed = Serial.parseInt();
    if (speed == 0){
      stop_engine();
    }
    if (speed > 0 && speed <= 255)
    {
      forward(speed);
    }
    //
    if (speed < 0 && speed >= -255){
      backward(speed * (-1));   
    }
  }
} 
