/** HEADER *******************************************************************
 * Author: Anthony Venturella                                                *
 * GitHub: https://github.com/AnthonyVenturella/UnityArduinoToyBox           *
 *---------------------------------------------------------------------------*/
/*  Description                                                              *
 *  Read_VertSpeed:                                                          *
 *    Program recieves data from Serial that is constrained by the range     *
 *    -20 <=> 20, it then maps to values that are calibrated to each servo.  *
 *    Purpose is for a vertical Speed indicator, made with a servo           *
 *                                                                           *
 *    Calibration:                                                           *
 *        servo Pos,     f/s                                                 *
 *        ==================                                                 *
 *        85       -   0   f/s                                               *
 *        159      -  ~22+ f/s (opposite of 85pos +)                         *
 *        154      -   20+ f/s                                               *
 *        14       -  ~22- f/s (opposite of 85pos -)                         *
 *        16       -   20- f/s                                               *
 *                                                                           *
 *---------------------------------------------------------------------------*/
/*  Expected Board Layout:                                                   *
 *                                                                           *
 *  +-----------------------------+                                          *
 *  |   +-+           +---+       |                                          *
 *  | +-|P|-----------|USB|---+   |                                          *
 *  | | |W|           +---+   |   |                                          *
 *  | | |R|                   |   |                                          *
 *  | | +-+            AREF[ ]|   |                                          *
 *  | |                 GND[ ]|   |                                          *
 *  | |[ ]IOREF   LED[+] 13[ ]|   |                                          *
 *  | |[ ]RESET          12[ ]|   |                                          *
 *  | |[ ]3.3V           11[ ]|   |          |==========|                    *
 *  +-|[+]5V             10[ ]|   |   +------]~         |                    *
 * +--|[-]GND             9[ ]|   |   |      |          |                    *
 * |  ~                       ~   +---|------]5V   Servo|                    *
 * |  |[ ]VIN             7[ ]|       |      |          |                    *
 * |  |                   6[+]|-------+   +--]GND       |                    *
 * |  ~                       ~           |  |==========|                    *
 * |  |                 ______/           |                                  *
 * |   \_______________/                  |                                  *
 * |                                      |                                  *
 * +--------------------------------------+                                  *
 *                                                                           *
 *****************************************************************************/
 

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
