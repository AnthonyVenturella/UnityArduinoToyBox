//on VSpeedDial
//    85   - 0 f/s
//    159 opposite of 85 +
//    154  - 20f/s +
//    14 opposite of 85 -
//    16  - 20f/s -

#include <Servo.h>

Servo VSpeedDial;
int servoPin = 6;

int servoLow = 16;
int servoHigh = 154;

void setup() {
  VSpeedDial.attach(servoPin);
  VSpeedDial.write(85);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    int vertSpeed = (int)(Serial.readStringUntil('\n').toFloat());

    VSpeedDial.write(constrain(map(vertSpeed, -20, 20, servoLow, servoHigh), servoLow, servoHigh));
  }
}
