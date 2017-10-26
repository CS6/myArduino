#include<LiquidCrystal.h>
LiquidCrystal lcd(12,7,5,4,3,2);
char ch;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
lcd.cursor();
lcd.blink();
lcd.home();
lcd.print("HELLO,LCD");
delay(2000);
lcd.setCursor(0,1);
lcd.print("Arduino..");
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()){
lcd.clear();
while(1){
  ch=Serial.read();
  if(ch=='\r'){
    Serial.println();
    break;
    }
    if(ch>0){  
      Serial.print(ch);
      lcd.print(ch);
      }
  }
}
}
