/** HEADER *******************************************************************
 * Author: Anthony Venturella                                                *
 * GitHub: https://github.com/AnthonyVenturella/UnityArduinoToyBox           *
 *---------------------------------------------------------------------------*/
/*  Description                                                              *
 *  USsensor:                                                                *
 *    Program constantly sends its read distance to serial to be picked up   *
 *    by the unity program. Outputto serial is distance from sensor to some  *
 *    object in cm.                                                          *
 *---------------------------------------------------------------------------*/
/*  Expected Board Layout:                                                   *
 *                                                                           *
 *      +-+           +---+                                                  *
 *    +-|P|-----------|USB|---+                                              *
 *    | |W|           +---+   |                                              *
 *    | |R|                   |                                              *
 *    | +-+            AREF[ ]|                                              *
 *    |                 GND[-]|---+                                          *
 *    |[ ]IOREF   LED[+] 13[ ]|   |          |==========|                    *
 *    |[ ]RESET          12[ ]|   +----------]GND       |                    *
 *    |[ ]3.3V           11[ ]|              |          |                    *
 * +--|[+]5V             10[ ]|       +------]Echo      |                    *
 * |  |[ ]GND             9[ ]|       |      |          | US sensor          *
 * |  ~                       ~   +---|------]Trig      |                    *
 * |  |[ ]VIN             7[+]|---+   |      |          |                    *
 * |  |                   6[-]|-------+   +--]Vcc       |                    *
 * |  ~                       ~           |  |==========|                    *
 * |  |                 ______/           |                                  *
 * |   \_______________/                  |                                  *
 * |                                      |                                  *
 * +--------------------------------------+                                  *
 *                                                                           *
 *****************************************************************************/

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
