char *morse[] = { "01", "1000", "1010", "100", "0", "0010", "110", "0000","00", "0111", "101", "0000","11", "10", "111", "0110","1101", "010", "000", "1","001", "0001", "011", "1001","1011", "1100", };


const byte  Buzzer = 10;
char chr, index;
char*ptr;


void setup() {


  pinMode(Buzzer, OUTPUT);
  Serial.begin(9600);

}

void loop() {

  if (Serial.available())
  {
    chr = Serial.read();
    Serial.println(chr);
    if ((chr - 'A') >= 0 && (chr - 'Z') <= 0)
      index = chr - 'A';
    ptr = morse[index];
    while (*ptr != '\0')
    {
      if (*ptr == '0')
      {
        tone(Buzzer, 440, 100);
        delay(100);

      }
      else
      {
        tone(Buzzer, 440, 300);
        delay(300);
      }
      ptr++;
      delay(100);
    }
    delay(300);
  }

}
