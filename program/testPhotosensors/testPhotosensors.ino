  //Photosensor PINS
  const int PHOTOSENSOR_1 = 11;
  const int PHOTOSENSOR_2 = 10;
  

  


void setup() {
  pinMode(PHOTOSENSOR_1, INPUT);
  pinMode(PHOTOSENSOR_2, INPUT);

    //Serielle Schnittstelle
  Serial.begin(9600);
}

void loop() {
int  PHOTO_1 = digitalRead(PHOTOSENSOR_1);
int  PHOTO_2 = digitalRead(PHOTOSENSOR_2);
  Serial.print(PHOTO_1);
  Serial.println(PHOTO_2);
  delay(2000);
}
