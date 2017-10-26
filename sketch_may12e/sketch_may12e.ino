 /*   
    2: Serial Call and Response   
    3: Language: Wiring/Arduino   
    4: This program sends an ASCII A (byte of value 65) on startup 程式一開始, 會持續送字元'A'由USB到電腦  
    5: and repeats that until it gets some data in. 直到Arduino 收到電腦送來資料.  
    6: Then it waits for a byte in the serial port, and 當它由USB收到資料後, 它就會送出三個感應器的值給電腦  
    7: sends three sensor values whenever it gets a byte in.   
    8: Thanks to Greg Shakar and Scott Fitzgerald for the improvements 感恩Greg 和 Scott 的修正  
    9: The circuit:   
    10: * potentiometers attached to analog inputs 0 and 1   
    11: * pushbutton attached to digital I/O 2   
    12: Created 26 Sept. 2005   
    13: by Tom Igoe   
    14: modified 24 April 2012   
    15: by Tom Igoe and Scott Fitzgerald 感恩Tom 和 Scott 的貢獻  
    16: This example code is in the public domain.   
    17: http://www.arduino.cc/en/Tutorial/SerialCallResponse   
    18: */   
  int firstSensor = 0; // first analog sensor 放第一個類比輸入的變數  
    int secondSensor = 0; // second analog sensor 放第二個類比輸入的變數  
  int thirdSensor = 0; // digital sensor 置放數位輸入的變數  
 int inByte = 0; // incoming serial byte 置放接收到的資料用  

 void setup()   
 {   
 ///start serial port at 9600 bps:   
 Serial.begin(9600); //設定USB 的傳輸速率  
     //while (!Serial) { //嗯. 這行, 好像李奧那多也不用耶. 可能是舊版的李奧那多才需要吧  
     // // wait for serial port to connect. Needed for Leonardo only   
      
     pinMode(2, INPUT); // digital sensor is on digital pin 2 設定pin 2為INPUT   
     establishContact(); // send a byte to establish contact until receiver responds 執行establishContact() 函式   
     }   
     void loop()   
     {   
      //if we get a valid byte, read analog ins:   
     if (Serial.available() > 0) { // 若有資料輸入, 則  
     // get incoming byte:   
     inByte = Serial.read(); // 將輸入的值放到inByte 變數內  
    // read first analog input, divide by 4 to make the range 0-255:   
     firstSensor = analogRead(A0)/4; //類比輸入為1024階,PWM只有256階, 所以將輸入的/4  
    ///delay 10ms to let the ADC recover:   
     delay(10);   
     // read second analog input, divide by 4 to make the range 0-255:   
     secondSensor = analogRead(1)/4; //同A0, 用map 也可以啦  
      ///read switch, map it to 0 or 255L   
     thirdSensor = map(digitalRead(2), 0, 1, 0, 255); //將數位輸入切換成 1 或 255  
     //send sensor values: //把三個轉換後的值傳送到USB  
     Serial.write(firstSensor);   
     Serial.write(secondSensor);   
     Serial.write(thirdSensor);   
     }   
     }   
     void establishContact() { // 用來建立連線的函式, 有點像送 Hello Packet.  
     while (Serial.available() <= 0) {   
     Serial.print('A'); // send a capital A   
     delay(300);   
     }   
     
     }

     
