void setup()
{
  Serial.begin(9600);
  pinMode(8, OUTPUT);

}

void loop()
{
  int val;
  val = analogRead(0);
  Serial.println(val, DEC);
  delay(1000);
  digitalWrite(8, HIGH);
}
