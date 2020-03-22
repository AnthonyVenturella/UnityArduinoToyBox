const int RED =  8;
const int GREEN =  9;
const int YELLOW = 10;
const int BLUE = 11;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    switch(Serial.readString().toInt()){
      case 1:
        digitalWrite(RED, !digitalRead(RED));
        break;
      case 2:
        digitalWrite(GREEN, !digitalRead(GREEN));
        break;
      case 3:
        digitalWrite(YELLOW, !digitalRead(YELLOW));
        break;
      case 4:
        digitalWrite(BLUE, !digitalRead(BLUE));
        break;
    }
  }
}
