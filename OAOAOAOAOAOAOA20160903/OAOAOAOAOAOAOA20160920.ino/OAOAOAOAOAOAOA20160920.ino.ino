/*
  SD card datalogger

 This example shows how to log data from three analog sensors
 to an SD card using the SD library.

 The circuit:
 * analog sensors on analog ins 0, 1, and 2
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4

 created  24 Nov 2010
 modified 9 Apr 2012
 by Tom Igoe

 This example code is in the public domain.

 */
 #include <SPI.h>
#include <SD.h>

const int chipSelect = 4;
#include <idDHT11.h>



int sensorValue = 1;  //輸出煙霧類比訊號用的PIN######
int Led = 7;                                          //設定LED腳位為第7孔
int buttonpin = 3;                                  //設定感測器D0腳位為第3孔
int Key1Pin = 5;  //輸出煙霧數位訊號用的PIN
int val;   //設定變量val
int H;
int oC;
int oF;
int oK;
int DPL;
int DPS;
int idDHT11pin = 2; //Digital pin for comunications
int idDHT11intNumber = 0; //interrupt number (must be the one that use the previus defined pin (see table above)
///int string =  DAAN;//////////////////////////////########
//declaration

void dht11_wrapper(); // must be declared before the lib initialization



// Lib instantiate

idDHT11 DHT11(idDHT11pin, idDHT11intNumber, dht11_wrapper);


void setup()
{
  Serial.begin(9600); // 設定Serial 傳輸速度
  pinMode(Led, OUTPUT);                    //設定LED为输出
  pinMode(buttonpin, INPUT);             //設定感測器D0为輸入

  Serial.println("idDHT11 Example program");

  Serial.print("LIB version: ");

  Serial.println(IDDHT11LIB_VERSION);

  Serial.println("---------------");
  ///////////////////////SD
 while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.print("Initializing SD card...");

  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");
  
}

#

// This wrapper is in charge of calling

// mus be defined like this for the lib work

void dht11_wrapper() {

  DHT11.isrCallback();

}
#
void loop()
{
  sensorValue = analogRead(0); //讀取數位 pin 0

  val = digitalRead(buttonpin);            //將感測器的值讀取給给val
  Serial.print("麥克風數字值 Mic Digital Value: ");
  Serial.println(val, DEC); // 顯示數位資料
  int keystate = digitalRead(Key1Pin); // 取得煙霧輸入PIN 腳的值
  Serial.print("Smoke A Value: "); // 顯示煙霧類比資料
  Serial.println(sensorValue, DEC); // 顯示煙霧類比資料
  Serial.print("Smoke D Value: "); // 顯示煙霧數位資料
  Serial.println(keystate, DEC); // 顯示煙霧數位資料

  if (val == HIGH)                                    //當感測器测有信號時，LED閃爍
  {
    digitalWrite(Led, HIGH);
  }
  else
  {
    digitalWrite(Led, LOW);

  }
  Serial.print("\nRetrieving information from sensor: ");

  Serial.print("Read sensor: ");

  Serial.println(" ");
  delay(100); //休息0.1秒

  int result = DHT11.acquireAndWait();

  switch (result)

  {

    case IDDHTLIB_OK:

      Serial.println("OK");

      break;

    case IDDHTLIB_ERROR_CHECKSUM:

      Serial.println("Error\n\r\tChecksum error");

      break;



    case IDDHTLIB_ERROR_ACQUIRING:

      Serial.println("Error\n\r\tAcquiring");

      break;

    case IDDHTLIB_ERROR_DELTA:

      Serial.println("Error\n\r\tDelta time to small");

      break;

    case IDDHTLIB_ERROR_NOTSTARTED:

      Serial.println("Error\n\r\tNot started");

      break;

    default:

      Serial.println("Unknown error");

      break;

  }

  Serial.print("濕度      Humidity (%): ");
  Serial.println(DHT11.getHumidity(), 2);
  Serial.print("攝氏      Temperature (oC): ");
  Serial.println(DHT11.getCelsius(), 2);
  Serial.print("華氏      Temperature (oF): ");
  Serial.println(DHT11.getFahrenheit(), 2);
  Serial.print("克氏溫標  Temperature (K): ");
  Serial.println(DHT11.getKelvin(), 2);
  Serial.print("露点温度H  Dew Point (oC): ");
  Serial.println(DHT11.getDewPoint());
  Serial.print(" 露点温度L  Dew Point Slow (oC):");
  Serial.println(DHT11.getDewPointSlow());



  delay(100);
  //////////////////SD
////   make a string for assembling the data to log:
  String dataString = "";

  // read three sensors and append to the string:
  for (int analogPin = 0; analogPin < 3; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }
 
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("datalog.txt", FILE_WRITE);
 H= (DHT11.getHumidity(), 2);
 oC=(DHT11.getCelsius(), 2);
oF=(DHT11.getFahrenheit(), 2);
oK=(DHT11.getKelvin(), 2);
 DPL=(DHT11.getDewPoint());
 DPS=(DHT11.getDewPointSlow());
  // if the file is available, write to it:
  if (dataFile) {
   /* ///////////////
 DAAN=val+" "+H+" "+oC+" "+oF+" "+oK+" "+DPL+" "+DPS;//////////////
    dataFile.println(DAAN);
   ////////////
     */
   dataFile.print(DHT11.getHumidity(), 2);
   dataFile.print(";濕度;");
   dataFile.print(DHT11.getCelsius(), 2);
   dataFile.print(";溫度C;");
   dataFile.print(DHT11.getFahrenheit(), 2);
   dataFile.print(";溫度F;");
   dataFile.print(DHT11.getKelvin(), 2);
   dataFile.print(";溫度K;");
   dataFile.print(DHT11.getDewPoint());
   dataFile.print(";路點溫度H;");
   dataFile.print(DHT11.getDewPointSlow());
   dataFile.println(";路點溫度L;");
  dataFile.close();
    // print to the serial port too: 
  Serial.println(DHT11.getHumidity(), 2);
  Serial.println(DHT11.getCelsius(), 2);
  Serial.println(DHT11.getFahrenheit(), 2);
  Serial.println(DHT11.getKelvin(), 2);
  Serial.println(DHT11.getDewPoint());
  Serial.println(DHT11.getDewPointSlow());
     delay(1000);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }

}




