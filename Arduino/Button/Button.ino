//signal comes in through pin 13 writes to serial

int Button = 13;

int val1;
int val2;
int buttonState;

void setup() {
  pinMode(Button, INPUT);
  Serial.begin(9600);
  buttonState = digitalRead(Button);
}

void loop() {
  val1 = digitalRead(Button);
  delay(10);
  val2 = digitalRead(Button);

  if(val1 == val2){
    if(val1 != buttonState){
      if(val1 == HIGH){
        Serial.println(1);
      }
    }
    buttonState = val1;
  }
}
