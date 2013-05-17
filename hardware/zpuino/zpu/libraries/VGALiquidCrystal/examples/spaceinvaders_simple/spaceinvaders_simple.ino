  /*
  VGA LiquidCrystal Library - Space Invaders Demo
 
  Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
  library works with all LCD displays that are compatible with the Hitachi HD44780 driver.
  
  This sketch is used for testing the lcd.createChar function. It first shows some text
  and than scrolls a space-invader pixel by pixel.
  
  Demo by JO3RI
  
  http://www.JO3RI.be/arduino/arduino-projects/lcd-16x2-demo
  
 Hardware:
 If using an Arcade MegaWing or a LogicStart MegaWing then select the appropriate "Hyperion" board type in the ZAP IDE.
 If using a VGA Wing or some other device then use the "Hyperion" pinselect board type in the ZAP IDE and be sure to uncomment "setup_pin_select" in setup.
 
 ZPUino Variant:
 Hyperion "The Lord of Light" with HQVGA adapter is needed for this example sketch  
 
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe 
 modified 25 July 2009
 by David A. Mellis
 modified 9/30/2010 - For Papilio Platform BPW5003 Wing
 by Jack Gassett (http://www.GadgetFactory.net) 
 modified 8/25/2011 - For VGA library output
 by Alvaro Lopes
 
 
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 
 */
 

// include the library code:
#include <VGA.h>
#include <VGALiquidCrystal.h>

#define B00000 0
#define B00001 1
#define B00010 2
#define B00011 3
#define B00100 4
#define B00101 5
#define B00110 6
#define B00111 7
#define B01000 8
#define B01001 9
#define B01010 10
#define B01011 11
#define B01100 12
#define B01101 13
#define B01110 14
#define B01111 15
#define B10000 16
#define B10001 17
#define B10010 18
#define B10011 19
#define B10100 20
#define B10101 21
#define B10110 22
#define B10111 23
#define B11000 24
#define B11001 25
#define B11010 26
#define B11011 27
#define B11100 28
#define B11101 29
#define B11110 30
#define B11111 31

#define HSync WING_A_1
#define VSync WING_A_0
#define Red0 WING_A_7
#define Red1 WING_A_5
#define Green0 WING_A_6
#define Green1 WING_A_4
#define Blue0 WING_A_2
#define Blue1 WING_A_3

void setup_pin_select() {
  pinMode(HSync,OUTPUT);
  digitalWrite(HSync,HIGH);
  outputPinForFunction(HSync, 15);
  pinModePPS(HSync, HIGH);

  pinMode(VSync,OUTPUT);
  digitalWrite(VSync,HIGH);
  outputPinForFunction(VSync, 14);
  pinModePPS(VSync, HIGH);   
  
  pinMode(Red0,OUTPUT);
  digitalWrite(Red0,HIGH);
  outputPinForFunction(Red0, 9);
  pinModePPS(Red0, HIGH);   

  pinMode(Red1,OUTPUT);
  digitalWrite(Red1,HIGH);
  outputPinForFunction(Red1, 8);
  pinModePPS(Red1, HIGH); 
  
  pinMode(Green0,OUTPUT);
  digitalWrite(Green0,HIGH);
  outputPinForFunction(Green0, 11);
  pinModePPS(Green0, HIGH); 

  pinMode(Green1,OUTPUT);
  digitalWrite(Green1,HIGH);
  outputPinForFunction(Green1, 10);
  pinModePPS(Green1, HIGH); 

  pinMode(Blue0,OUTPUT);
  digitalWrite(Blue0,HIGH);
  outputPinForFunction(Blue0, 13);
  pinModePPS(Blue0, HIGH); 

  pinMode(Blue1,OUTPUT);
  digitalWrite(Blue1,HIGH);
  outputPinForFunction(Blue1, 12);
  pinModePPS(Blue1, HIGH);     
}

// initialize the library with the numbers of the interface pins
VGALiquidCrystal lcd(1,1,1,1,1,1);

// set for space invader animation speed:
int y=250;

// drawing the pixels for each 8x5 part of the LCD (SPACE INVADER)
// --START SPACE INVADER--
// --EMPTY START--
byte charSP0[8] = {
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000,
 B00000
};
// --EMPTY END--

// --MOVE STEP A START--
byte charSP1a[8] = {
 B00000,
 B00000,
 B00000,
 B10000,
 B10000,
 B00000,
 B00000,
 B10000
};

byte charSP2a[8] = {
 B00000,
 B00000,
 B10000,
 B11000,
 B11000,
 B00000,
 B10000,
 B01000
};

byte charSP3a[8] = {
 B00000,
 B10000,
 B11000,
 B01100,
 B11100,
 B10000,
 B01000,
 B10100
};

byte charSP4a[8] = {
 B10000,
 B11000,
 B11100,
 B10110,
 B11110,
 B01000,
 B10100,
 B01010
};

byte charSP5a[8] = {
 B11000,
 B11100,
 B11110,
 B11011,
 B11111,
 B00100,
 B11010,
 B00101
};

byte charSP6a[8] = {
 B01100,
 B11110,
 B11111,
 B01101,
 B11111,
 B10010,
 B01101,
 B10010
};


byte charSP7a[8] = {
 B00110,
 B01111,
 B11111,
 B10110,
 B11111,
 B01001,
 B10110,
 B01001
};

byte charSP8a[8] = {
 B00011,
 B00111,
 B01111,
 B11011,
 B11111,
 B00100,
 B01011,
 B10100
};

byte charSP9a[8] = {
 B00001,
 B00011,
 B00111,
 B01101,
 B01111,
 B00001,
 B00010,
 B00101
};

byte charSP10a[8] = {
 B00000,
 B00001,
 B00011,
 B00110,
 B00111,
 B00001,
 B00010,
 B00101
};

byte charSP11a[8] = {
 B00000,
 B00000,
 B00001,
 B00011,
 B00011,
 B00000,
 B00001,
 B00010
};

byte charSP12a[8] = {
 B00000,
 B00000,
 B00000,
 B00001,
 B00001,
 B00000,
 B00000,
 B00001
};
// --MOVE STEP A END--

// --MOVE STEP B START--
byte charSP1b[8] = {
 B00000,
 B00000,
 B00000,
 B10000,
 B10000,
 B00000,
 B10000,
 B00000
};

byte charSP2b[8] = {
 B00000,
 B00000,
 B10000,
 B11000,
 B11000,
 B10000,
 B01000,
 B10000
};

byte charSP3b[8] = {
 B00000,
 B10000,
 B11000,
 B01100,
 B11100,
 B01000,
 B00100,
 B01000
};

byte charSP4b[8] = {
 B10000,
 B11000,
 B11100,
 B10110,
 B11110,
 B10100,
 B00010,
 B00100
};

byte charSP5b[8] = {
 B11000,
 B11100,
 B11110,
 B11011,
 B11111,
 B11010,
 B00001,
 B00010
};

byte charSP6b[8] = {
 B01100,
 B11110,
 B11111,
 B01101,
 B11111,
 B01101,
 B00000,
 B00001
};

byte charSP7b[8] = {
 B00110,
 B01111,
 B11111,
 B10110,
 B11111,
 B10110,
 B00000,
 B10000
};

byte charSP8b[8] = {
 B00011,
 B00111,
 B01111,
 B11011,
 B11111,
 B01011,
 B10000,
 B01000
};

byte charSP9b[8] = {
 B00001,
 B00011,
 B00111,
 B01101,
 B01111,
 B00101,
 B01000,
 B00100
};

byte charSP10b[8] = {
 B00000,
 B00001,
 B00011,
 B00110,
 B00111,
 B00010,
 B00100,
 B00010
};

byte charSP11b[8] = {
 B00000,
 B00000,
 B00001,
 B00011,
 B00011,
 B00001,
 B00010,
 B00001
};

byte charSP12b[8] = {
 B00000,
 B00000,
 B00000,
 B00001,
 B00001,
 B00000,
 B00001,
 B00000
};
// --MOVE STEP B END--
// --END SPACE INVADER--


void setup() {
  
  //Uncomment this if you are using the pinselect variant
  //setup_pin_select();
  VGA.clear();
/*  pinMode(AH7, OUTPUT);     //Set contrast to GND
 digitalWrite(AH7, LOW);   //Set contrast to GND
 */
 // set up the LCD's number of columns and rows:
 lcd.begin(16,2);
 // clear the LCD screen:
 lcd.clear();
}


void loop() {
 // start the welcome part:
 welcome();
 // start the space invader part:
 space01();
}

//set up the welcome part
void welcome(){
   lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("PAPILIO LCD DEMO");
 lcd.setCursor(1,1);
 lcd.print("ZPUINO INSIDE!");
 delay(3000);
 lcd.clear();
 lcd.setCursor(4,0);
 lcd.print("DEMO BY:");
 lcd.setCursor(2,1);
 lcd.print("www.JO3RI.be");
 delay(3000);
}        

//set up the space invader animation and make it move
void space01(){
 for (int a=0; a<13;a+=2)
 {
 int b=a+1;
 int c=a+2;
 int d=a+3;
 int e=a+4;
 lcd.clear();
 lcd.setCursor(1,1);
 lcd.print("SPACE INVADERS");
 lcd.createChar(0, charSP12a);
 lcd.createChar(1, charSP7a);
 lcd.createChar(2, charSP2a);
 lcd.createChar(3, charSP0);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(1);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(3);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(1, charSP8b);
 lcd.createChar(2, charSP3b);
 lcd.createChar(3, charSP0);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(1);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(3);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(1, charSP9a);
 lcd.createChar(2, charSP4a);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(1);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(0);
 lcd.setCursor(e,0);
 lcd.write(0);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(1, charSP10b);
 lcd.createChar(2, charSP5b);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(1);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(0);
 lcd.setCursor(e,0);
 lcd.write(0);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(1, charSP11a);
 lcd.createChar(2, charSP6a);
 lcd.createChar(3, charSP1a);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(1);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(0);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(1, charSP12b);
 lcd.createChar(2, charSP7b);
 lcd.createChar(3, charSP2b);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(1);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(0);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(1, charSP0);
 lcd.createChar(2, charSP8a);
 lcd.createChar(3, charSP3a);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(1);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(0);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(2, charSP9b);
 lcd.createChar(3, charSP4b);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(0);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(0);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(2, charSP10a);
 lcd.createChar(3, charSP5a);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(0);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(0);
 delay(y);
 lcd.createChar(0, charSP0);
 lcd.createChar(2, charSP11b);
 lcd.createChar(3, charSP6b);
 lcd.createChar(4, charSP1b);
 lcd.setCursor(a,0);
 lcd.write(0);
 lcd.setCursor(b,0);
 lcd.write(0);
 lcd.setCursor(c,0);
 lcd.write(2);
 lcd.setCursor(d,0);
 lcd.write(3);
 lcd.setCursor(e,0);
 lcd.write(4);
 delay(y);
 }
}


