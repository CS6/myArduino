#define X_PIN A0
#define Y_PIN A1
#define Z_PIN A2

void setup(){
  Serial.begin(19200);
  // 注意，在呼叫analogRead之前必須先呼叫analogReference
  analogReference(EXTERNAL);
}
// 將類比輸入的值轉成g
float toG(float v){
  return v * 6 / 1023 - 3;
}
void loop(){
  int x  = analogRead(X_PIN);
  int y  = analogRead(Y_PIN);
  int z  = analogRead(Z_PIN);
 
  Serial.print("X: ");
  Serial.print(x);
  Serial.print(", Y: ");
  Serial.print(y);
  Serial.print(", Z: ");
  Serial.print(z);
  Serial.print(";  X: ");
  Serial.print(toG(x));
  Serial.print("g, Y: ");
  Serial.print(toG(y));
  Serial.print("g, Z: ");
  Serial.print(toG(z));
  Serial.println("g");
  delay(100);
}
