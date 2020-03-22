/** HEADER *******************************************************************
 * Author: Anthony Venturella                                                *
 * GitHub: https://github.com/AnthonyVenturella/UnityArduinoToyBox           *
 *---------------------------------------------------------------------------*/
/*  Description                                                              *
 *  Read_LED:                                                                *
 *    Program recieves data from serial one line at a time, parses into int  *
 *    then takes that integer and uses as case for switch statment to toggle *
 *    various LED lights.                                                    *
 *---------------------------------------------------------------------------*/
/*  Expected Board Layout:                                                   *
 *                                                                           *
 *    +-+           +---+                                                    *
 *  +-|P|-----------|USB|---+                                                *
 *  | |W|           +---+   |                                                *
 *  | |R|                   |                                                *
 *  | +-+            AREF[ ]|                                                *
 *  |                 GND[-]|-------------------------+                      *
 *  |[ ]IOREF   LED[+] 13[ ]|                         |                      *
 *  |[ ]RESET          12[ ]|                         |                      *
 *  |[ ]3.3V           11[+]|---[220ohm]----[BLUE]>|--+                      *
 *  |[+]5V             10[+]|---[220ohm]--[YELLOW]>|--+                      *
 *  |[-]GND             9[+]|---[220ohm]---[GREEN]>|--+                      *
 *  |[ ]GND             8[+]|---[220ohm]-----[RED]>|--+                      *
 *  ~                       ~                                                *
 *  |[ ]A4              1[ ]|                                                *
 *  |[ ]A5              0[ ]|                                                *
 *  |                 ______/                                                *
 *   \_______________/                                                       *
 *                                                                           *
 *****************************************************************************/

const int RED    =  8;
const int GREEN  =  9;
const int YELLOW = 10;
const int BLUE   = 11;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(BLUE, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    switch(Serial.readStringUntil('\n').toInt()){
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
      case 5:
        digitalWrite(RED,    LOW);
        digitalWrite(GREEN,  LOW);
        digitalWrite(YELLOW, LOW);
        digitalWrite(BLUE,   LOW);
        break;
    }
  }
}
