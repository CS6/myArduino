const int seg7[]={11,10,9,8,7,6,5,4};
const int scan[]={3,2,1,0};
const int prowpin[]={12,13};
int delaytime=5;
char TAB[]={0xFF,0xFE,0xFD,0xFC,0xFB,0xFA,0xF9,0xF8,0xF7};
int ii,jj,zz,hh;
int ScanLine=0;


void setup() {
  // put your setup code here, to run once:
  for(ii=0;ii<7;ii++){
    pinMode(seg7[ii],OUTPUT);
  }
for(ii=0;ii<4;ii++)
{
  pinMode(scan[ii],OUTPUT);
digitalWrite(scan[ii],LOW);
  }
 for(zz=0;zz<2;zz++)
{
  pinMode(prowpin[zz],OUTPUT);
digitalWrite(prowpin[zz],HIGH);
  } 
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available())
{
  delaytime=Serial.parseInt();
  Serial.print(delaytime);
  Serial.println("MS");
  }
  OutPort(TAB[2]);
}

void OutPort(byte dat){
  for(jj=0;jj<8;jj++)
  {
    if(dat%2==1)
      digitalWrite(seg7[jj],HIGH);
    else
      digitalWrite(seg7[jj],LOW);
     dat=dat/2;
     
    }
  
  }
