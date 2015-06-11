/*
 Gadget Factory - Servo Pan and Tilt
 To learn more about using DesignLab please visit http://learn.gadgetfactory.net

 Tutorials:

 Related library documentation:

 Hardware:
   Any Papilio board - Works with ZPUino or AVR
   
 Special Notes:

 created 2014
 by Jack Gassett
 http://www.gadgetfactory.net
 
 This example code is in the public domain.
 */

#define circuit ZPUino_Vanilla

#include <Servo.h> 
#include <Timer.h>
 
Servo tilt;  // create servo object to control a servo 
Servo pan;
                // twelve servo objects can be created on most boards
 
int pos = 0;    // variable to store the servo position 
int panpos = 0;
 
void setup() 
{ 
  Serial.begin(115200);
  tilt.attach(6);  // attaches the servo on pin 9 to the servo object 
  pan.attach(7);
} 
 
void loop() 
{ 
  for(pos = 90; pos <= 180; pos += 1) // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    tilt.write(pos);              // tell servo to go to position in variable 'pos' 
    pan.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=90; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    tilt.write(pos);              // tell servo to go to position in variable 'pos' 
    pan.write(pos);
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
} 

