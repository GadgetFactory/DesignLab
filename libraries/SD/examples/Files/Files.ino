/*
  SD card basic file example
 
 This example shows how to create and destroy an SD card file 	
 The circuit:
 A microSD Wing connected to AL ( http://www.papilio.cc/index.php?n=Papilio.MicroSDWing )
 or
 A RetroCade MegaWing ( http://retrocade.gadgetfactory.net/index.php?n=Main.RetroCadeMegaWing )
 
 Soft Processor:
 This example is for the ZPUino Soft Processor, it will work with any variant that has SPI connected to Wishbone slot 6 such as the Hyperion variant.
  ( http://papilio.gadgetfactory.net/index.php?n=Papilio.Hyperion )
 
 created   Nov 2010
 by David A. Mellis
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

File myFile;

void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);

  Serial.print("Initializing SD card...");


  if (!SD.begin(CSPIN, WISHBONESLOT)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");
  }

  // open a new file and immediately close it:
  Serial.println("Creating example.txt...");
  myFile = SD.open("example.txt", FILE_WRITE);
  myFile.close();

  // Check to see if the file exists: 
  if (SD.exists("example.txt")) {
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }

  // delete the file:
  Serial.println("Removing example.txt...");
  SD.remove("example.txt");

  if (SD.exists("example.txt")){ 
    Serial.println("example.txt exists.");
  }
  else {
    Serial.println("example.txt doesn't exist.");  
  }
}

void loop()
{
  // nothing happens after setup finishes.
}


