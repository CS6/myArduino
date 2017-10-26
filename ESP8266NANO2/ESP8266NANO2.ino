
///#define SSID  "Physical Fu Burst"      // change this to match your WiFi SSID




/*
 *
 * Once connect to target Access Point
 *
 */
 #include <ESP8266_TCP.h>;
 
// ESP8266 Class
 ESP8266_TCP wifi;
 
// Target Access Point
 #define ssid <Physical Fu Burst>;
 #define pass <22476103>;
 
// Connect this pin to CH_PD pin on ESP8266
 #define PIN_RESET 6
 
void setup()
 {
 delay(3000);
 
// and use Serial to debugging
 Serial.begin(115200);
 wifi.begin(Serial, PIN_RESET);
 
// Check that ESP8266 is available
 if(wifi.test())
 {
 // Connect to Access Point
 wifi.connectAccessPoint(ssid, pass);
 Serial.println("Connected to WiFi.")
 }
 else
 {
 // ESP8266 isn't available
 Serial.println("Check module connection and restart to try again...");
 }
 }
 
void loop()
{
}
