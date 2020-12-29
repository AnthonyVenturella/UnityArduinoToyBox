# UnityArduinoToyBox HEAVILY WIP
A Unity Program that takes various Arduino input via Serial

Unity version: 2019.3.0f6

## Description
I had worked on this over last spring break after I noticed C# has support for making connections via serial the same way an Arduino does, with the intention of getting an Arduino Uno to communicate with Unity for some fun. However, I never got around to cleaning up any of the code or writing detailed instructions so I never posted it anywhere. But I figure there is probably someone weird like me who finds this interesting. Now fair warning I haven't taken any networking classes (and thats totally the excuse I'm using for why I left the joystick and US sensor code so janky) so if you have any improvement ideas feel free to take it and play with it however you want, or send me improvements!

If you want to try it out and are confused as to how I cobbled it together let me know, but here is some necessary instructions:

Arduino code is in Arduino folder all the code includes a wiring diagram (none are large circuits)
Unity project contains several scenes. Intro scene will take you to the different scenes, or you can just launch whichever scene you want
You will need to edit each of the unity scripts to change the com port your Arduino is hooked up to
If Arduino is hooked up right, and unity is running with no errors you should be connected and able to interact

### Button.ino / Button Scene
![Button](Media/Button.gif)

##Button:

This ones an output from the Arduino to Unity. Its simple and straight forward, the Arduino sends a simple packet to Unity and Unity reads it in and changes the color of the block. The color change is random but seemingly instantaneous.


### Read_LED.ino / LEDlights Scene
![LED Lights](Media/LEDLights.gif)

##LEDLights:

This one is an output from Unity to the Arduino. It is also simple and straight forward, When a user selects a button that button sends a unique value to the Arduino that corresponds to that colors pin-out. The Arduino reads it and then toggles the correct pin (the last menu option turns them all off).


### Read_VertSpeed.ino / VertSpeed Scene
![](Media/VertSpeed.gif)

## VertSpeed:

This ones an output from Unity to the Arduino. Unity sends the blocks velocity to the Arduino via serial, and the Arduino takes that packet and maps it to the range of motion for this vertical speed display. You'll notice as the block reaches its highest point the VertSpeed display reads zero, and you can just catch when it hits the ground it snaps back to zero as well. The space bar adds +10 to its upward velocity. This display is just a small servo (the one that usually comes in Arduino kits) inside a 3D printed display. The Arduino code is specifically calibrated for this display and the range of motion can be edited.


# The below are somewhat working, but need heavy work.

## Joystick And USsensor:

These are very broken, They'll work for a couple seconds then lag very far behind. I think its due to me spamming the serial with data, but I've never gotten around to fixing them. But basically both are outputs from the Arduino to Unity. They will move the blocks around for a little bit but then quickly fall apart. Feel free to fix these!

### Joystick.ino / Joystick Scene
![](Media/Joystick.gif)
Joystick code needs a lot of work as the deadzone seems large and it has a tendincy to only move along one axis at a time.


### USsensor.ino / USsensor Scene
![](Media/USsensor.gif)
