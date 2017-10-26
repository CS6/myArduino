#define LEDR 9
#define LEDG 10
#define LEDB 11

void setup() {                
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

int r = 0;
int g = 0;
int b = 0;
void loop() {
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);
  analogWrite(LEDR, r);
  analogWrite(LEDG, g);
  analogWrite(LEDB, b);
  delay(1000);
}
