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
//#include <SPI.h>
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

File root;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  int i;

  Serial.print("Initializing SD card...");

  if (!SD.begin(CSPIN, WISHBONESLOT)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

}

void loop()
{
  Serial.println("\n\nStarting List Files:"); 
  root = SD.open("/");
  
  printDirectory(root, 0);
  
  Serial.println("List Files complete, waiting 5 seconds.");
  delay(5000);
}

void printDirectory(File dir, int numTabs) {
   while(true) {
     
     File entry =  dir.openNextFile();
     if (! entry) {
       // no more files
       //Serial.println("**nomorefiles**");
       break;
     }
     for (uint8_t i=0; i<numTabs; i++) {
       Serial.print('\t');
     }
     Serial.print(entry.name());
     if (entry.isDirectory()) {
       Serial.println("/");
       printDirectory(entry, numTabs+1);
     } else {
       // files have sizes, directories do not
       Serial.print("\t\t");
       Serial.println(entry.size(), DEC);
     }
     entry.close();
   }
}


