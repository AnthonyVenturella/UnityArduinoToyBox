//serial output is in cm

const int trigPin = 7;
const int echoPin = 6;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  long duration, cm;

  //Send short low pulse in order to get a clean high pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //send a high pulse of 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //pulsein captures amount of time until recieve the echo back
  duration = pulseIn(echoPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  
  Serial.println(cm);
}

long microsecondsToCentimeters(long microseconds) {
  //sound travels at 29.155 microseconds per centimeter in Air
  //need to divide that number by 2 to account for travel there and back
  return (microseconds / 29) / 2;
}
