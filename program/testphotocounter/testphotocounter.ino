
//%%%%%%%%%%%%%%%%%%%%%%%Photosensor%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Photosensor PINS
const int PHOTOSENSOR_1 = 12;
const int PHOTOSENSOR_2 = 11;
//putput values
int PHOTO_1;
int PHOTO_2;
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



void setup() {


  //%%%%%%%%%%%%%%%%%%%%%%%Photosensor%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //Photosensor auf INPUT  
  pinMode(PHOTOSENSOR_1, INPUT);
  pinMode(PHOTOSENSOR_2, INPUT);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%



  //Serielle Schnittstelle
  Serial.begin(9600);

}



  int oldPHOTO_1 = 0;
  int oldPHOTO_2 = 0;
  int stepcounter = 0;
int i=0;
  
void loop() {
  //read values
  PHOTO_1 = digitalRead(PHOTOSENSOR_1);
  PHOTO_2 = digitalRead(PHOTOSENSOR_2);
  
  i=i+1;
  
  
  if (oldPHOTO_1 == HIGH) {
    if (PHOTO_1 == LOW){
      if (oldPHOTO_2 == HIGH && PHOTO_2 == HIGH) {stepcounter++;}
      else if (oldPHOTO_2 == LOW && PHOTO_2 == LOW){stepcounter--;} 
      oldPHOTO_1 = LOW;
    }

    else { //PHOTO_1 = HIGH
      if (oldPHOTO_2 == LOW && PHOTO_2 == HIGH) {stepcounter++; oldPHOTO_2 = HIGH;}
      if (oldPHOTO_2 == HIGH && PHOTO_2 == LOW) {stepcounter--; oldPHOTO_2 = LOW;}
    }
  }

  else { //oldPHOTO_1 = LOW
    if (PHOTO_1 == HIGH){
      if (oldPHOTO_2 == LOW && PHOTO_2 == LOW) {stepcounter++;}
      else if (oldPHOTO_2 == HIGH && PHOTO_2 == HIGH) {stepcounter--;} 
      oldPHOTO_1 = HIGH;
    }

    else { //PHOTO_1 = LOW
      if (oldPHOTO_2 == LOW && PHOTO_2 == HIGH) {stepcounter--; oldPHOTO_2 = HIGH;}
      if (oldPHOTO_2 == HIGH && PHOTO_2 == LOW) {stepcounter++; oldPHOTO_2 = LOW;}
    }
  }

  //output
if (i%100000==0){
  //Serial.println(i);
  Serial.println(stepcounter);
}
}
