/*
  PIR("Passive Infrared Sensor") Motion Sensor, 
  紅外線動作感測器, 或稱人體紅外線感測器
 */

const int PIRSensor = 2;     // 紅外線動作感測器連接的腳位
const int ledPin =  13;      // LED 腳位

int sensorValue = 0;         // 紅外線動作感測器訊號變數

void setup() {
  pinMode(PIRSensor, INPUT);     
  pinMode(ledPin, OUTPUT);        
}

void loop(){
  // 讀取 PIR Sensor 的狀態
  sensorValue = digitalRead(PIRSensor);

  // 判斷 PIR Sensor 的狀態
  if (sensorValue == HIGH) {     
    digitalWrite(ledPin, HIGH);  // 有人，開燈
  } 
  else {
    digitalWrite(ledPin, LOW);   // 沒人，關燈
  }
}
