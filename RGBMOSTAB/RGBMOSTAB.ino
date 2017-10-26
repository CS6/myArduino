int ledR = 9;
int ledG = 10;
int ledB = 11;

int brightness = 0;    // how bright the LED is
int fadeAmount = 5;  

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
  // 設定輸出腳位
  for (byte i = 0; i < NUM_OF_SW; i++) {
    pinMode(swPins[i], OUTPUT);
  }
  pinMode(LedR, OUTPUT);                    //設定LED为输出
  pinMode(LedG, OUTPUT);  
  pinMode(LedB, OUTPUT);  
 
  Serial.println("idDHT11 Example program");

  Serial.print("LIB version: ");

  Serial.println("RGB//RGB");

  Serial.println("---------------");

}

void loop() {

  analogWrite(ledR, brightness);

  brightness = brightness + fadeAmount;

  
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ;
  }
  delay(300);
}
