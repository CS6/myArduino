int T[] = { 0,1,2,3,4,5,6,7,8,9,10,11 };
int i = 0;
int y = 0;
int p = 0;
int R = 0;///������
int B[] = { 0,1,2,3 };
int Q[] = { 1,2,3,4,5,6,7,8 };
int PW[] = { 12,13 };
int LLED[] = { 11,10,9,8 };
int RLED[] = { 7,6,5,4 };
const int prowerPin = PW[p];
const int buttonPin[] = { 3,2,1,0 };
const int byteplurs[] = { 8,4,2,1 };
const int LEDPin = T[i];
int RRR;

int ii;






void setup()
{
	pinMode(prowerPin, OUTPUT);
	pinMode(LEDPin, INPUT);
	/* add setup code here */
	pinMode(LEDPin, INPUT);
	Serial.begin(9600);
}

void loop()
{
	if (LEDPin == HIGH)
	{
		digitalWrite(LEDPin, HIGH);
		delay(100);
	}
	RRR = 0;
	for (ii = 0;ii<4;ii++)
	{
		int reading = digitalRead(buttonPin[ii]);
		if (reading == LOW)RRR += byteplurs[ii];
	}
	if (RRR<10)  
	{
		RLED[ii] = (RRR / 10) / 2;
			LLED[ii] = LOW;

	}




	/* add main program code here */

}
