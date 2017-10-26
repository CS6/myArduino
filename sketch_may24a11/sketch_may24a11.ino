int T[]={1,2,3,4,5,6,7,8};
int Q[]={11,10,9,8};
int P[]={7,6,5,4};
int Y[]={4,5,6,7,8,9,10,11};
int Pures[]={8,4,2,1};
const int DIP[]={3,2,1,0};
int ii;
int hh;
int qq;
int pp;
int sw;
int tt;
int jj;
int number;
//int DIP[]={3,2,1,0};
//const int DIPPin=DIP[sw];
int seg7[]={4,5,6,7,8,9,10,11};
//const int UUUpin=Y[hh];
const int LEDPin = T[tt];
char TAB[]={0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11000000,0b11111111};
///{0x00,0x0E,0x0D,0x0C,0x0B,0x0A,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x02,0x01,0x11,0xFF,0xF0,0x0F};
void setup() {
  // put your setup code here, to run once:
    for(sw=0;sw<4;sw++)
    {
      pinMode(DIP[sw],INPUT_PULLUP);
      }
  
  /* add setup code here */
  pinMode(seg7[jj], OUTPUT);
  Serial.begin(9600);
}

void loop() {
  number=0;
  for(sw=0;sw<4;sw++)
  {
    int reading=digitalRead(DIP[sw]);
    if(reading==LOW)number += Pures[sw];
    }
  // put your main code here, to run repeatedly:
  for(tt=0;tt<8;tt++)
  {
if (LEDPin == LOW)
  {
    digitalWrite(LEDPin, LOW);
    delay(100);
  }
  }
  OutPort(TAB[number]);
}

void OutPort(byte dat)
{
  for(jj=0;jj<8;jj++)
  {
    if(dat%2==1)
    digitalWrite(seg7[jj],LOW);
   else
    digitalWrite(seg7[jj],HIGH);
    dat=dat/2;
    }
    
    }
  
