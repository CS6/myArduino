int LightPin = A0;
int vul;
int Led = 13;      
void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600); // 設定Serial 傳輸速度
  pinMode(Led, OUTPUT);                    //設定LED为输出
   //設定感測器D0为輸入
}

void loop() {
  // put your main code here, to run repeatedly:
  vul = digitalRead(LightPin);
  Serial.println(vul);
   if (vul == 1)                                    //當感測器测有信號時，LED閃爍
  {
    digitalWrite(Led, HIGH); ///// digital是數位
  }
  else
  {
    digitalWrite(Led, LOW);

  }
  
}
