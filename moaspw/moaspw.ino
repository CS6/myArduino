/*
2: Serial Call and Response
3: Language: Wiring/Arduino
4: This program sends an ASCII A (byte of value 65) on startup �{���@�}�l, �|����e�r��'A'��USB��q��
5: and repeats that until it gets some data in. ����Arduino ����q���e�Ӹ��.
6: Then it waits for a byte in the serial port, and ����USB�����ƫ�, ���N�|�e�X�T�ӷP�������ȵ��q��
7: sends three sensor values whenever it gets a byte in.
8: Thanks to Greg Shakar and Scott Fitzgerald for the improvements �P��Greg �M Scott ���ץ�
9: The circuit:
10: * potentiometers attached to analog inputs 0 and 1
11: * pushbutton attached to digital I/O 2
12: Created 26 Sept. 2005
13: by Tom Igoe
14: modified 24 April 2012
15: by Tom Igoe and Scott Fitzgerald �P��Tom �M Scott ���^�m
16: This example code is in the public domain.
17: http://www.arduino.cc/en/Tutorial/SerialCallResponse
18: */
int firstSensor = 0; // first analog sensor ��Ĥ@�������J���ܼ�  
int secondSensor = 0; // second analog sensor ��ĤG�������J���ܼ�  
int thirdSensor = 0; // digital sensor �m��Ʀ��J���ܼ�  
int inByte = 0; // incoming serial byte �m�񱵦��쪺��ƥ�  

void setup()
{
	///start serial port at 9600 bps:   
	Serial.begin(9600); //�]�wUSB ���ǿ�t�v  
						//while (!Serial) { //��. �o��, �n���������h�]���έC. �i��O�ª����������h�~�ݭn�a  
						// // wait for serial port to connect. Needed for Leonardo only   

	pinMode(2, INPUT); // digital sensor is on digital pin 2 �]�wpin 2��INPUT   
	establishContact(); // send a byte to establish contact until receiver responds ����establishContact() �禡   
}
void loop()
{
	//if we get a valid byte, read analog ins:   
	if (Serial.available() > 0) { // �Y����ƿ�J, �h  
								  // get incoming byte:   
		inByte = Serial.read(); // �N��J���ȩ��inByte �ܼƤ�  
								// read first analog input, divide by 4 to make the range 0-255:   
		firstSensor = analogRead(A0) / 4; //�����J��1024��,PWM�u��256��, �ҥH�N��J��/4  
										  ///delay 10ms to let the ADC recover:   
		delay(10);
		// read second analog input, divide by 4 to make the range 0-255:   
		secondSensor = analogRead(1) / 4; //�PA0, ��map �]�i�H��  
										  ///read switch, map it to 0 or 255L   
		thirdSensor = map(digitalRead(2), 0, 1, 0, 255); //�N�Ʀ��J������ 1 �� 255  
														 //send sensor values: //��T���ഫ�᪺�ȶǰe��USB  
		Serial.write(firstSensor);
		Serial.write(secondSensor);
		Serial.write(thirdSensor);
	}
}
void establishContact() { // �Ψӫإ߳s�u���禡, ���I���e Hello Packet.  
	while (Serial.available() <= 0) {
		Serial.print('A'); // send a capital A   
		delay(300);
	}
	if (Serial.available() > 0) {
		Serial.print(firstSensor);
		Serial.print(secondSensor);
		Serial.print(thirdSensor);
	}
}

