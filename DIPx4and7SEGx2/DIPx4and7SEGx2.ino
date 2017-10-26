const int DIP[]={3,2,1,0};
const byte Weight[]={8,4,2,1};
int seg7[]={4,5,6,7,8,9,10,11};
char TAB[]={0x3F,0x06,0x58,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71};
int ii,jj;
int number;
void setup() {
  // put your setup code here, to run once:
for(ii=0;ii<8;ii++)
{
  pinMode(seg7[ii],OUTPUT);
    }
for(ii=0;ii<4;ii++)
{
  pinMode(DIP[ii],INPUT_PULLUP);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
number=0;
for(ii=0;ii<4;ii++)
{
  int reading=digitalRead(DIP[ii]);
  if(reading==LOW)number+=Weight[ii];
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
