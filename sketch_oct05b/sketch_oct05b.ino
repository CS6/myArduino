int brightness = 0;
 int fadeAmount = 5;
 int delayDuration = 60; 

 void setup()  {
   pinMode(3, OUTPUT);
 }

 void loop()  {
   analogWrite(3, brightness);//////analog+Write
   brightness = brightness + fadeAmount;
   if (brightness <= 0 || brightness >= 255) {
     fadeAmount = -fadeAmount ;
   }    

   delay(delayDuration);                            
 }
