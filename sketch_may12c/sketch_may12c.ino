#include "Arduino.h"
#include "JoystickLib.h"
 
Joystick stick(A0, A1);
 
void setup() {
   Serial.begin(9600);
   while(!Serial) {
      delay(10);
   }
 
   // Calibrate the joystick. For this to be effective, the joystick should
   // be resting at its center position.
   stick.calibrate();
}
 
void loop() {
   // Both axis values should be:
   // Center = 0
   // Farthest left (X) or farthest down (Y) = -100
   // Farthest right (X) or farthest up (Y) = 100
   // Or any value in between. Make sure you call loop() first.
   stick.loop();
 
   // Print the X-axis value.
   Serial.print(F("X = "));
   Serial.printlin(stick.getX());
 
   // Print the Y-axis value.
   Serial.print(F("Y = "));
   Serial.println(stick.getY());
   delay(500); 
}
if (stick.isUp()) {
   Serial.println(F("Stick is up"));
}
 
if (stick.isDown()) {
   Serial.println(F("Stick is down."));
}
void printPosition() {
   Serial.print(F("X: "));
   Serial.println(stick.getX());
   Serial.print(F("Y: "));
   Serial.println(stick.getY());
   Serial.println();
}
 
void onUpHandler() {
   Serial.println(F("Direction: Up"));
   printPosition();
}
 
void onDownHandler() {
   Serial.println(F("Direction: Down"));
   printPosition();
}
 
void setup() {
   Serial.begin(9600);
   stick.calibrate();
   stick.onUp(onUpHandler);
   stick.onDown(onDownHandler);
}
 
void loop() {
   stick.loop();
   delay(300);  // Delay not necessary.  Just added to make it easier to read the output.  
}
const int AXIS_THRESHOLD = 30;
 
void onUpHandler() {
   if (stick.getY() > AXIS_THRESHOLD) {
      // Do stuff only if the Y-axis is greater than 30.
      // This way we know the movement was more deliberate.
   }
}
