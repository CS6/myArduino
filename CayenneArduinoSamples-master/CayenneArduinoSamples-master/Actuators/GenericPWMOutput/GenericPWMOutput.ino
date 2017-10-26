/*
Cayenne Generic PWM Output Example

This sketch shows how to set up a Generic PWM Output with Cayenne.

The Cayenne Library is required to run this sketch. If you have not already done so you can install it from the Arduino IDE Library Manager.

Steps:
1. In the Cayenne Dashboard add a new Generic PWM Output.
2. Select a virtual pin number.
2. Select a slider widget.
3. Set min value to 0 and max value of 1.
4. Set PWM_VIRTUAL_PIN to the virtual pin number you selected.
3. Attach an output device to a digital PWM pin (3, 5, 6, 9, 10, and 11 on most Arduino boards).
6. Set PWM_DIGITAL_PIN to the digital PWM pin number you selected.
7. Set the token variable to match the Arduino token from the Dashboard.
8. Compile and upload this sketch.
9. Once the Arduino connects to the Dashboard you can use the slider to change PWM values.
*/


#define CAYENNE_PRINT Serial  // Comment this out to disable prints and save space
#include <CayenneEthernet.h>
#define PWM_VIRTUAL_PIN 1
#define PWM_DIGITAL_PIN 3

// Cayenne authentication token. This should be obtained from the Cayenne Dashboard.
char token[] = "AuthenticationToken";

void setup()
{
	Serial.begin(9600);
	Cayenne.begin(token);
}

CAYENNE_IN(PWM_VIRTUAL_PIN)
{
	// get value sent from dashboard
	int currentValue = getValue.asInt(); // 0 to 1023
	analogWrite(PWM_DIGITAL_PIN, currentValue / 4); // must be from 0 to 255
}

void loop()
{
	Cayenne.run();
}