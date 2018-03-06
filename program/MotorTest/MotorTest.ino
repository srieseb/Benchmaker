int motor1_A=11;
int motor1_B=10;
int motor1_Speed=9;
 

void setup(){
  pinMode(motor1_A,OUTPUT);
  pinMode(motor1_B,OUTPUT);

  Serial.begin(9600);
}
void loop() {
   // motor1
  for (int i=0; i<256; i+=50){
    digitalWrite(motor1_A,HIGH); // A = HIGH and B = LOW means the motor will turn right
    digitalWrite(motor1_B,LOW);
    analogWrite(motor1_Speed,i); // speed counts from 0 to 255
    Serial.println("right");
    Serial.println(i);
    delay(200);
  }
  for (int i=255; i>50; i-=50){
    digitalWrite(motor1_A,HIGH); // A = HIGH and B = LOW means the motor will turn right
    digitalWrite(motor1_B,LOW);
    analogWrite(motor1_Speed,i); // speed counts from 0 to 255
    Serial.println("right");
    Serial.println(i);
    delay(200);
  }
  delay(2000);
   // motor1
  for (int i=0; i<256; i+=50){
    digitalWrite(motor1_A,LOW); // A = LOW and B = HIGH means the motor will turn left
    digitalWrite(motor1_B,HIGH);
    analogWrite(motor1_Speed,i); // speed counts from 0 to 255
    Serial.println("right");
    Serial.println(i);
    delay(200);
  }
  for (int i=255; i>50; i-=50){
    digitalWrite(motor1_A,LOW); // A = LOW and B = HIGH means the motor will turn left
    digitalWrite(motor1_B,HIGH);
    analogWrite(motor1_Speed,i); // speed counts from 0 to 255
    Serial.println("right");
    Serial.println(i);
    delay(200);
  }
}
