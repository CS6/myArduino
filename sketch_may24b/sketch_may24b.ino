
int omg;
int prowpin[] = {12, 13};
const int swpin[] = {3, 2, 1, 0};
int T[] = {8, 7, 6, 5, 4, 3, 2, 1};

int ii;
const int LEDPin = T[ii];
void setup() {
  // put your setup code here, to run once:


  /* add setup code here */
  for (ii = 0; ii < 8; ii++)
  {
    pinMode(T[ii], OUTPUT);
  }

pinMode(prowpin[0],OUTPUT);
  
  //pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 /* if (digitalRead(swpin[3]) == HIGH)
  {
    ///pinMode(prowpin[0],OUTPUT);
    digitalWrite(prowpin[0], HIGH);
    digitalWrite(prowpin[1], LOW);



  }*/
  if(digitalRead(swpin[3])==LOW)
  {
    digitalWrite(prowpin[1],HIGH);
    digitalWrite(prowpin[0],LOW);
  }
  else
  {
    digitalWrite(prowpin[0],HIGH);
    digitalWrite(prowpin[1],LOW);
  }

  digitalWrite(prowpin[0],HIGH);
  
  // put your main code here, to run repeatedly:
  for (ii = 0; ii < 8; ii++) {
    //if (LEDPin == LOW)
    //{
    digitalWrite(T[ii], LOW);
    delay(100);
    digitalWrite(T[ii],HIGH);
    //}
  }
}
