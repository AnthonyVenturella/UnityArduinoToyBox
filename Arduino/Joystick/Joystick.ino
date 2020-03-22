const int Button = 13;
const int XAxis = 0;
const int YAxis = 1;

int buttonState = 1;

void setup() {
  pinMode(Button, INPUT);
  Serial.begin(9600);
}

void loop() {

  //TODO: code that looks awful, but gets button input once. FIX ME!
  int buttonVal = digitalRead(Button);
  if(buttonVal != buttonState){
    if(buttonVal == HIGH) {
      Serial.print(0);
    } else {
      Serial.print(1);
    }
    buttonState = buttonVal;
  } else {
    Serial.print(0);
  }
  
  Serial.print(',');
  Serial.print(analogRead(XAxis));
  Serial.print(',');
  Serial.println(analogRead(YAxis));
}
