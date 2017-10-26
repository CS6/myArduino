
#include <idDHT11.h>



int sensorValue = 1;  //輸出煙霧類比訊號用的PIN######
int Led = 13;                                          //設定LED腳位為第13孔
int buttonpin = 3;                                  //設定感測器D0腳位為第3孔
int Key1Pin = 4;  //輸出煙霧數位訊號用的PIN
int val;                                                     //設定變量val

int idDHT11pin = 2; //Digital pin for comunications
int idDHT11intNumber = 0; //interrupt number (must be the one that use the previus defined pin (see table above)

//declaration

void dht11_wrapper(); // must be declared before the lib initialization

 

// Lib instantiate

idDHT11 DHT11(idDHT11pin,idDHT11intNumber,dht11_wrapper);


void setup()
{
  Serial.begin(9600); // 設定Serial 傳輸速度
  pinMode(Led, OUTPUT);                    //設定LED为输出
  pinMode(buttonpin, INPUT);             //設定感測器D0为輸入

  Serial.println("idDHT11 Example program");

  Serial.print("LIB version: ");

  Serial.println(IDDHT11LIB_VERSION);

  Serial.println("---------------");
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
  Serial.print("Mic Digital Value: ");
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

  Serial.print("Humidity (%): ");

  Serial.println(DHT11.getHumidity(), 2);

 

  Serial.print("Temperature (oC): ");

  Serial.println(DHT11.getCelsius(), 2);

 

  Serial.print("Temperature (oF): ");

  Serial.println(DHT11.getFahrenheit(), 2);

 

  Serial.print("Temperature (K): ");

  Serial.println(DHT11.getKelvin(), 2);

 

  Serial.print("Dew Point (oC): ");

  Serial.println(DHT11.getDewPoint());

 

  Serial.print("Dew Point Slow (oC): ");

  Serial.println(DHT11.getDewPointSlow());

 

  delay(2000);
}




