#include <Wire.h>
#define SLAVE_ADDRESS 0x40   // Define the i2c address
#include <dht.h>

dht DHT;

#define DHT_PIN 4
byte sendInfo[3];
void setup(){
  Serial.begin(9600);
  Wire.begin(SLAVE_ADDRESS); 
}

void loop(){
  // read data
  int chk = DHT.read22(DHT_PIN);
  switch(chk){
    case DHTLIB_OK:
      Serial.print("OK,\t");
      break;
     case DHTLIB_ERROR_CHECKSUM:
      Serial.print("Checksum error,\t");
      break;
     case DHTLIB_ERROR_TIMEOUT:
      Serial.print("Time out error,\t");
      break;
    case DHTLIB_ERROR_CONNECT:
      Serial.print("Connect error,\t");
      break;
    case DHTLIB_ERROR_ACK_L:
      Serial.print("Ack Low error,\t");
      break;
    case DHTLIB_ERROR_ACK_H:
      Serial.print("Ack High error,\t");
      break;
    default:
      Serial.print("Unknown error,\t");
      break;
    }
    Serial.print("temperature,:");
    Serial.print(DHT.temperature);
    Serial.print(",humidity:");
    Serial.println(DHT.humidity);
    Wire.onRequest(sendData);
    delay(1000);
}
  
void sendData(){
  sendInfo[0] = (byte)((DHT.temperature < 0) ? 1 : 0);
  sendInfo[1] = (byte)((DHT.temperature < 0) ? (DHT.temperature*(-1)) : DHT.temperature);
  sendInfo[2] = (byte)(DHT.humidity);
  Wire.write(sendInfo, 3);
}
