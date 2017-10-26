#include <Wire.h>

int I2C_Address = 0xA7 >> 1; // ADXL345 的 I2C 地址

int X0, X1, Y0, Y1, Z1, Z0;
float X,Y,Z;

void setup(){
    Serial.begin(9600);
    Serial.println("Start : \n------------------------------------");
    
    Wire.begin();  //初始化 I2C
    setReg(0x2D, 0xA); // (打開電源, 設定輸出資料速度為 100 Hz)  
}

void loop(){
    X0 = getData(0x32); // 取得 X 軸 低位元資料
    X1 = getData(0x33); // 取得 X 軸 高位元資料
    X = ((X1 << 8)  + X0) / 256.0;
 
    Y0 = getData(0x34); // 取得 Y 軸 低位元資料
    Y1 = getData(0x35); // 取得 Y 軸 高位元資料
    Y = ((Y1 << 8)  + Y0) / 256.0;
 
    Z0 = getData(0x36); // 取得 Z 軸 低位元資料
    Z1 = getData(0x37); // 取得 Y 軸 高位元資料
    Z = ((Z1 << 8)  + Z0) / 256.0;
    
    Serial.print("X= ");
    Serial.print(X);
    Serial.print("    Y= ");
    Serial.print(Y);
    Serial.print("    Z= ");
    Serial.println(Z);
    
    delay(500);
}

/* setReg(reg,data)：寫入佔存器
 * 參數：
 *     reg → 指定佔存器位址
 *     data → 要寫入的資料
 */
void setReg(int reg, int data){
    Wire.beginTransmission(I2C_Address);
    Wire.write(reg); // 指定佔存器
    Wire.write(data); // 寫入資料
    Wire.endTransmission();
}

/* getData(reg)：取得佔存器裡的資料
 * 參數：reg → 佔存器位址
 */
int getData(int reg){
    Wire.beginTransmission(I2C_Address);
    Wire.write(reg);
    Wire.endTransmission();
    
    Wire.requestFrom(I2C_Address,1);
    
    if(Wire.available()<=1){
        return Wire.read();
    }
}

 



