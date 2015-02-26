/*
  SD card read/write
 
 This example shows how to read and write data to and from an SD card file 	
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

  delay(2000); //wait 2 seconds for people to get the serial monitor open.

  Serial.print("Initializing SD card...");
   
  if (!SD.begin(CSPIN, WISHBONESLOT)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");
  
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  Serial.println("Opening test.txt");
  myFile = SD.open("test.txt", FILE_WRITE);
  
  // if the file opened okay, write to it:
  if (myFile) {
    Serial.print("Writing to test.txt...");
    myFile.println("testing 1, 2, 3.");
	// close the file:
    myFile.flush();
    myFile.close();
    Serial.println("done.");
  } else {
    // if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
  
  // re-open the file for reading:
  myFile = SD.open("test.txt");
  if (myFile) {
    Serial.println("test.txt:");
    
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
    	Serial.write(myFile.read());
    }
    // close the file:
    myFile.close();
  } else {
  	// if the file didn't open, print an error:
    Serial.println("error opening test.txt");
  }
}

void loop()
{
	// nothing happens after setup
}

