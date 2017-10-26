// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

#include "DHT.h"
#define CAYENNE_DEBUG         // Cayenne Code Uncomment to show debug messages
#define DHTPIN 2              // what digital pin we're connected to
#define CAYENNE_PRINT Serial  // Cayenne Code Comment this out to disable prints and save space
#include <CayenneEthernet.h>  // Cayenne Code Change this to use a different communication device. See Communications examples.

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "g1cgkkfrr2";

// Uncomment whatever type you're using!
#define DHTTYPE DHT11   // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor

// Initialize DHT sensor.
// Note that older versions of this library took an optional third parameter to
// tweak the timings for faster processors.  This parameter is no longer needed
// as the current DHT reading algorithm adjusts itself to work on faster procs.
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  Cayenne.begin(token);
  dht.begin();
}

void loop() {
  Cayenne.run();
  
  // Wait a few seconds between measurements.
  delay(10000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");


}

// These functions are called when the Cayenne widget requests data for the Virtual Pin.
CAYENNE_OUT(V0)
{
  Cayenne.virtualWrite(V0, dht.readTemperature(true));
}

CAYENNE_OUT(V1)
{
  Cayenne.virtualWrite(V1, dht.readHumidity());
}

CAYENNE_OUT(V2)
{
  Cayenne.virtualWrite(V2, dht.readTemperature());
}

CAYENNE_OUT(V3)
{
  Cayenne.virtualWrite(V3, dht.readHumidity());
}

CAYENNE_OUT(V4)
{
  Cayenne.virtualWrite(V4, dht.readTemperature(true));
}
