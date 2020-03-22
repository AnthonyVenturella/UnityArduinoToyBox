/** HEADER *******************************************************************
 * Author: Anthony Venturella                                                *
 * GitHub: https://github.com/AnthonyVenturella                              *
 *---------------------------------------------------------------------------*/
/*  Description                                                              *
 *  Button:                                                                  *
 *    Program sends an integer to Serial when a button is pressed.           *
 *    Default button pin is pin 13, default integer sent to Serial is 1      *
 *---------------------------------------------------------------------------*/
/*  Expected Board Layout:                                                   *
 *                                                                           *
 *  +--------------------------------------------+                           *
 *  |   +-+           +---+                      |                           *
 *  | +-|P|-----------|USB|---+                  |                           *
 *  | | |W|           +---+   |                  |                           *
 *  | | |R|                   |                  |                           *
 *  | | +-+            AREF[ ]|                  |                           *
 *  | |                 GND[ ]|                  |                           *
 *  | |[ ]IOREF   LED[+] 13[-]|--]==[-[220ohm]-+ |                           *
 *  | |[ ]RESET          12[ ]|  |SW|          | |                           *
 *  | |[ ]3.3V           11[ ]|  ]==[------------+                           *
 *  +-|[+]5V             10[ ]|                |                             *
 * +--|[-]GND             9[ ]|                |                             *
 * |  ~                       ~                |                             *
 * |  |[ ]A3              2[ ]|                |                             *
 * |  |[ ]A4              1[ ]|                |                             *
 * |  |[ ]A5              0[ ]|                |                             *
 * |  |                 ______/                |                             *
 * |   \_______________/                       |                             *
 * |                                           |                             *
 * +-------------------------------------------+                             *
 *                                                                           *
 *****************************************************************************/

//Default values for button input and value to send to Serial
const int Button = 13;
const int SendVal = 1;

int val1;         //for reading in a button pres
int val2;         //for comparing in a debounce
int buttonState;  //stores button state so 1 press = 1 press

void setup() {
  pinMode(Button, INPUT);
  Serial.begin(9600);
  buttonState = digitalRead(Button);
}

void loop() {

  //Brooklyn Debounce
  val1 = digitalRead(Button);
  delay(10);
  val2 = digitalRead(Button);

  if(val1 == val2){
    if(val1 != buttonState){
      if(val1 == HIGH){
        Serial.println(SendVal);
      }
    }
    //storing button state for next loop check. Makes sure only reads once
    buttonState = val1;
  }
}
