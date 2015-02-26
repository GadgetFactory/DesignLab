/*
  SD card file dump
 
 This example shows how to read a file from the SD card using the
 SD library and send it over the serial port.

 created  22 December 2010
 by Limor Fried
 modified 9 Apr 2012
 by Tom Igoe
 modified 6/3/2013
 by Jack Gassett for the Papilio
 
 This example code is in the public domain.
 	 
 */

#include <SD.h>
#include "SPI.h"

//Uncomment for the SD card on the Papilio DUO Computing Shield
//#define circuit Computing_Shield
//#define CSPIN  16
//#define WISHBONESLOT 12

//Uncomment for a SD card connected to the CL Wing Slot.
#define circuit ZPUino_Wings
#define CSPIN  WING_CL4
#define WISHBONESLOT 12

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600); 
  
  delay(3000);

  Serial.print("Initializing SD card...");

  pinMode(CSPIN,OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(CSPIN, WISHBONESLOT)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    //return;
  }
  Serial.println("card initialized.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  // make sure test.txt exists
  Serial.println("Opening test.txt");
  File dataFile = SD.open("test.txt");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  }  
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening test.txt");
  } 
}

void loop()
{
}
