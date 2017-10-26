int Led=13;                                              //設定LED接腳在第13孔


int buttonpin=3;                                      //設定火焰感測器接腳在第3孔


int val;                                                      //設定變量val


void setup()


{ 


pinMode(Led,OUTPUT);                      //設定LED為输出


pinMode(buttonpin,INPUT);                //設定感測器为输入


}


void loop()


{


val=digitalRead(buttonpin);                  //將感測器的值讀取给val


if(val==HIGH)                                          //當感測器檢測有信號时，LED 閃爍


{ 


digitalWrite(Led,HIGH);


}


else


{ 


digitalWrite(Led,LOW);


}


}
