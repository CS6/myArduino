
int T[]={4,5,6,7,8,9,10,11};
int ii;
const int LEDPin = T[ii];
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  for(ii=0;ii<9;ii++){
if (LEDPin == HIGH)
  {
    digitalWrite(LEDPin, HIGH);
    delay(100);
  }
  }
}
