/*
 # This sample code is used to test the pH meter V1.0.
 # Editor : YouYou
 # Ver    : 1.0
 # Product: analog pH meter
 # SKU    : SEN0161
*/
// 匯入程式庫標頭檔 
#include <OneWire.h>
#include <DallasTemperature.h>
#define LEDR 9
#define LEDG 10
#define LEDB 11
// Arduino數位腳位2接到1-Wire裝置
#define ONE_WIRE_BUS 2
#define SensorPin A0            //pH meter Analog output to Arduino Analog Input 0
#define Offset 0.00            //deviation compensate

#define samplingInterval 20
#define printInterval 800
#define ArrayLenth  40    //times of collection
//#define ONE_WIRE_BUS 4
// 運用程式庫建立物件
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

int pHArray[ArrayLenth];   //Store the average value of the sensor feedback
int pHArrayIndex=0;    
void setup(void)
{
    pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
  //pinMode(LED,OUTPUT);  
 // Serial.begin(9600);  
  Serial.println("pH meter experiment!");    //Test the serial monitor
 Serial.begin(115200);
  Serial.println("Temperature Sensor");
  // 初始化 
  sensors.begin();
}


void loop(void)
{
  static unsigned long samplingTime = millis();
  static unsigned long printTime = millis();
  static float pHValue,voltage;
  if(millis()-samplingTime > samplingInterval)
  {
      pHArray[pHArrayIndex++]=analogRead(SensorPin);
      if(pHArrayIndex==ArrayLenth)pHArrayIndex=0;
      voltage = avergearray(pHArray, ArrayLenth)*5.0/1024;
      pHValue = 3.5*voltage+Offset;
      samplingTime=millis();
  }
  if(millis() - printTime > printInterval)   //Every 800 milliseconds, print a numerical, convert the state of the LED indicator
  {
  Serial.print("Voltage:");
        Serial.print(voltage,2);
        Serial.print("    pH value: ");
  Serial.println(pHValue,2);
        //digitalWrite(LED,digitalRead(LED)^1);
        printTime=millis();
  }
/////////////
 // 要求匯流排上的所有感測器進行溫度轉換（不過我只有一個） 
 // sensors.requestTemperatures();
    Serial.print(" Requesting temperatures...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("DONE");

  // 取得溫度讀數（攝氏）並輸出，
  // 參數0代表匯流排上第0個1-Wire裝置 
  Serial.println(sensors.getTempCByIndex(0));
 if  (sensors.getTempCByIndex(0) >15)
 {
   Serial.println("Normal");
 analogWrite(LEDR, 255);
   analogWrite(LEDG, 255);
   analogWrite(LEDB, 0);
  }
   if  (sensors.getTempCByIndex(0) >35)
 {
   Serial.println("HOT");
   analogWrite(LEDR, 0);
   analogWrite(LEDG, 255);
   analogWrite(LEDB, 255);
  }
   if  (sensors.getTempCByIndex(0) <15)
   {
     Serial.println("is Cold dead I'm frozen/stiff.");

       analogWrite(LEDR, 255);
   analogWrite(LEDG, 0);
   analogWrite(LEDB, 255);

    }
  //Serial.print("] [");
   // Serial.println(sensors.getTempFByIndex(1));


  delay(1000);

  
}
double avergearray(int* arr, int number){
  int i;
  int max,min;
  double avg;
  long amount=0;
  if(number<=0){
    Serial.println("Error number for the array to avraging!/n");
    return 0;
  }
  if(number<5){   //less than 5, calculated directly statistics
    for(i=0;i<number;i++){
      amount+=arr[i];
    }
    avg = amount/number;
    return avg;
  }else{
    if(arr[0]<arr[1]){
      min = arr[0];max=arr[1];
    }
    else{
      min=arr[1];max=arr[0];
    }
    for(i=2;i<number;i++){
      if(arr[i]<min){
        amount+=min;        //arr<min
        min=arr[i];
      }else {
        if(arr[i]>max){
          amount+=max;    //arr>max
          max=arr[i];
        }else{
          amount+=arr[i]; //min<=arr<=max
        }
      }//if
    }//for
    avg = (double)amount/(number-2);
  }//if
  return avg;
}
