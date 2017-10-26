const int DIP[]={3,2,1,0};
const byte Weight[]={8,4,2,1};
int seg7[]={4,5,6,7,8,9,10,11};
//char TAB[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x27,0x7F,0x67,0x77,0x7C,0x39,0x5E,0x79,0x71};
char TAB[]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0xF8,0x09,0x10,0x11,0x12,0x13,0x14,0x15};
//char TAB[]={0000 0000,0000 0001};
//char TAB[]={0x15,0x14,0x13,0x12,0x11,0x10,0x09,0x08,0x07,0x06,0x05,0x04,0x03,0x22,0x01,0x00};
int prowpin=13;

int ii,jj;
int number;
void setup() {
  // put your setup code here, to run once:
  pinMode(prowpin,OUTPUT);
  digitalWrite(prowpin,HIGH);
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
    digitalWrite(seg7[jj],HIGH);
   else
    digitalWrite(seg7[jj],LOW);
    dat=dat/2;
    }
    
    }
