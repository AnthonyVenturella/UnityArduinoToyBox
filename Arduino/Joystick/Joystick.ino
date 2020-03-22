/** HEADER *******************************************************************
 * Author: Anthony Venturella                                                *
 * GitHub: https://github.com/AnthonyVenturella/UnityArduinoToyBox           *
 *---------------------------------------------------------------------------*/
/*  Description                                                              *
 *  Joystick:                                                                *
 *    Program sends positional data from an analog joystick of the form      *
 *    "Button, X-Axis, Y-Axis" to Serial. Resting state is 0,~500,~500.      *
 *    Default button pin is 13, default x-axis is A0, default y-axis is A1   *
 *---------------------------------------------------------------------------*/
/*  Expected Board Layout:                                                   *
 *                                                                           *
 *  +-------------------------------------------+                            *
 *  |      +-+           +---+                  |                            *
 *  |    +-|P|-----------|USB|---+              |                            *
 *  |    | |W|           +---+   |              |                            *
 *  |    | |R|                   |              |                            *
 *  |    | +-+            AREF[ ]|              |                            *
 *  |    |                 GND[-]|----------------+                          *
 *  |    |[ ]IOREF   LED[+] 13[-]|---+          | |                          *
 *  |    |[ ]RESET          12[ ]|   |          | | /==============\         *
 *  |    |[ ]3.3V           11[ ]|   |          | +-]GND           |         *
 *  +----|[+]5V             10[ ]|   |          +---]+5V           |         *
 *       |[-]GND             9[ ]|   |        +-----]VRx  Joystick |         *
 *       ~                       ~   |        | +---]VRy           |         *
 *   +---|[-]A0              5[ ]|   +--------------]SW            |         *
 *   | +-|[-]A1              4[ ]|            | |   \==============/         *
 *   | | |[ ]A2              3[ ]|            | |                            *
 *   | | ~                       ~            | |                            *
 *   | | |                 ______/            | |                            *
 *   | |  \_______________/                   | |                            *
 *   | |                                      | |                            *
 *   | +----------------------------------------+                            *
 *   +----------------------------------------+                              *
 *                                                                           *
 *****************************************************************************/

const int Button = 13;
const int XAxis = 0;
const int ZAxis = 1;

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
  Serial.println(analogRead(ZAxis));
}
