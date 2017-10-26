// Watch video here: https://www.youtube.com/watch?v=235BLk7vk00

/* 將震動感測器與 Arduino UNO 的接線方式:
 Arduino Vibration Sensor
 D9 DOut
 GND GND
 +5V VCC 
  D13  LED 燈  
*/

int ledPin = 13;
int EP =9;

void setup(){
 pinMode(ledPin, OUTPUT);
 pinMode(EP, INPUT); //set EP input for measurment
 Serial.begin(9600); //init serial 9600
 // Serial.println("----------------------Vibration demo------------------------");
}
void loop(){
 long measurement =TP_init();
 delay(50);
 // Serial.print("measurment = ");
 Serial.println(measurement);
 if (measurement > 1000){
 digitalWrite(ledPin, HIGH);
 }
 else{
 digitalWrite(ledPin, LOW); 
 }
}

long TP_init(){
 delay(10);
 long measurement=pulseIn (EP, HIGH); //wait for the pin to get HIGH and returns measurement
 return measurement;
}
