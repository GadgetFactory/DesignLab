/*
 Gadget Factory
 Template to make your own Schematic Symbol and Community Core Library for the Papilio FPGA and DesignLab

 To use this sketch do the following steps:
  1) 
  
 Tools for generating your own libraries:
 

 Tutorials:
   http://learn.gadgetfactory.net
  

 created 2014
 by Jack Gassett
 http://www.gadgetfactory.net
 
 This example code is in the public domain.
 */
#define circuit AVR_Wishbone_Bridge

#include "AVR_Wishbone_Bridge.h"
#include "AVR_Wishbone_Bridge_Test.h"
#include "SPI.h"

AVR_Wishbone_Bridge_Test AVR_Wishbone_Bridge_Test;
 
void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  Serial.begin(9600);
  AVR_Wishbone_Bridge_Test.setup(5);   
  
}

void loop() {
	Serial.println(AVR_Wishbone_Bridge_Test.readButtons());
	AVR_Wishbone_Bridge_Test.writeLEDs(0xf);

  //REGISTER(IO_SLOT(5),0) = 0xf;
  //Serial.println(REGISTER(IO_SLOT(5),1));
  
  delay(1000);
}
