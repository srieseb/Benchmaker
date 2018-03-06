//%%%%%%%%%%%%%%%%%%%%%%%Set Motor Pins%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
#define motor1_A 11
#define motor1_B 10
#define motor1_Speed 9
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//%%%%%%%%%%%%%%%%%%%%%%%Photosensor%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Photosensor PINS
const byte PHOTOSENSOR_1 =2; //has to be interruptPIN (normal value)

//putput values
int PHOTO_1;
int PHOTO_2;
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


#include "functions.h"


 


void setup(){
  //Set MotorPins to Output
  pinMode(motor1_A,OUTPUT);
  pinMode(motor1_B,OUTPUT);


  //Set Photosensor to INPUT  
  pinMode(PHOTOSENSOR_1, INPUT_PULLUP);
 

  //Serial port
  Serial.begin(9600);

  attachInterrupt(digitalPinToInterrupt(PHOTOSENSOR_1), count, CHANGE);
}


//boolean old_direction; false = backward, true = forward
int stepcounter = 0;

//Interrupt function
//Counts Steps made
void count(){
  if(old_direction){
    stepcounter++;
  }
  else stepcounter--;
  Serial.println(stepcounter);
}

void loop() {
  // Serial controlled Motor running
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
    if (speed < 0 && speed >= -255){
      backward(speed * (-1));   
    }
  }
} 
