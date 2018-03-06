#include <Arduino.h>

boolean old_direction; // false = backward, true = forward




void start_engine(int speed){
  analogWrite(motor1_Speed,speed); // speed counts from 0 to 255
}

void stop_engine(){
  analogWrite(motor1_Speed,0); // speed counts from 0 to 255
}

void forward(int speed){
   if (!old_direction){
    digitalWrite(motor1_A,HIGH); // A = HIGH and B = LOW means the motor will turn right
    digitalWrite(motor1_B,LOW);
   }
   old_direction = true;
   Serial.println("forward");
   start_engine(speed);
}

void backward(int speed){
  if (old_direction){
    digitalWrite(motor1_A,LOW); // A = LOW and B = HIGH means the motor will turn left
    digitalWrite(motor1_B,HIGH);
  }
  old_direction = false;
  Serial.println("backward");
  start_engine(speed);
}

