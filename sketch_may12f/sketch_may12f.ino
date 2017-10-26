const int xAxis = A0;         // joystick X axis
const int yAxis = A1;   
int range = 12;               // output range of X or Y movement
int responseDelay = 5;        // response delay of the mouse, in ms
int threshold = range / 4;    // resting threshold
int center = range / 2;    
boolean mouseIsActive = false;    // whether or not to control the mouse
int lastSwitchState = LOW;        // previous switch state// resting position value
void setup() {
  // put your setup code here, to run once:

}

void loop() {
 
  
  
  
  
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);// put your main code here, to run repeatedly:
}
void establishContact() { // 用來建立連線的函式, 有點像送 Hello Packet.  
     while (1) {   
     Serial.print("X"+"y"); // send a capital A   
     
     delay(300);   
     }   
     }   
int readAxis(int thisAxis) {
  // read the analog input:
  int reading = analogRead(thisAxis);

  // map the reading from the analog input range to the output range:
  reading = map(reading, 0, 1023, 0, range);

  // if the output reading is outside from the
  // rest position threshold,  use it:
  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  // return the distance for this axis:
  return distance;
}     
