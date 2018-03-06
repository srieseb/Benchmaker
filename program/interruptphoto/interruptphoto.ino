//%%%%%%%%%%%%%%%%%%%%%%%Photosensor%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//Photosensor PINS
const byte PHOTOSENSOR_1 =2; //has to be interruptPIN (normal value)
const int PHOTOSENSOR_2 =1; // choose interrupt PIN
//putput values
int PHOTO_1;
int PHOTO_2;
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void setup() {
  //%%%%%%%%%%%%%%%%%%%%%%%Photosensor%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  //Photosensor auf INPUT  
  pinMode(PHOTOSENSOR_1, INPUT_PULLUP);
  pinMode(PHOTOSENSOR_2, INPUT);
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

  //Serielle Schnittstelle
  Serial.begin(9600);

attachInterrupt(digitalPinToInterrupt(PHOTOSENSOR_1), count, CHANGE);
//attachInterrupt(PHOTOSENSOR_2, set2, CHANGE);
}

int stepcounter = 0;

 
void loop()
{
  for (int i = 0; i < 1000; i++)
  {
   delay(100);
  }
}

 
void count(){
  stepcounter++;
  Serial.println(stepcounter);
}




