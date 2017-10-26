#include <Servo.h>

Servo myservo; // 建立Servo物件，控制伺服馬達

void setup()
{
myservo.attach(0); // 連接數位腳位0，伺服馬達的訊號線
myservo.attach(0, 500, 2400); // 修正脈衝寬度範圍
myservo.write(90); //初始定位於90度角
}

void loop()
{

for(int i = 179; i >= 0; i-- ){
myservo.write(i); 
delay(100);
}
delay(2000);
for(int i = 0; i <= 179; i++){
myservo.write(i);// 使用write，從0度轉到90度
delay(100);
}
delay(2000);

}
