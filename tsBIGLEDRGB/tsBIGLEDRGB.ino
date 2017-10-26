/*
 Fade

 This example shows how to fade an LED on pin 9
 using the analogWrite() function.

 The analogWrite() function uses PWM, so if
 you want to change the pin you're using, be
 sure to use another PWM capable pin. On most
 Arduino, the PWM pins are identified with 
 a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

 This example code is in the public domain.
 */

int ledR = 8;           // the PWM pin the LED is attached to
int ledG = 9;           // the PWM pin the LED is attached to
int ledB = 10;           // the PWM pin the LED is attached to
int brightnessR = 0;
int brightnessG = 0;
int brightnessB = 0;// how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // set the brightness of pin 9:
  analogWrite(ledR, brightnessR);
 analogWrite(ledG, brightnessG);
  analogWrite(ledB, brightnessB);
  // change the brightness for next time through the loop:
  brightnessR = brightnessR + fadeAmount;
brightnessG = brightnessG + fadeAmount;
brightnessB = brightnessB + fadeAmount;
  // reverse the direction of the fading at the ends of the fade:
  if (brightnessR == 0 || brightnessR == 255) {
    fadeAmount = -fadeAmount ;
  }
   delay(1000);
  if (brightnessG == 0 || brightnessG == 255) {
    fadeAmount = -fadeAmount ;
  }
   delay(1000);
  if (brightnessB == 0 || brightnessB == 255) {
    fadeAmount = -fadeAmount ;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(1000);
}
