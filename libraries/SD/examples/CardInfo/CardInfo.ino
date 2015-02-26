/*
  SD card test 
   
 This example shows how use the utility libraries on which the'
 SD library is based in order to get info about your SD card.
 Very useful for testing a card when you're not sure whether its working or not.

 created  28 Mar 2011
 by Limor Fried 
 modified 9 Apr 2012
 by Tom Igoe
 modified 6/3/2013
 by Jack Gassett for the Papilio
 */
 // include the SD library:
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


// set up variables using the SD utility library functions:
Sd2Card card;
SdVolume volume;
SdFile root;


void setup()
{
 // Open serial communications and wait for port to open:
  Serial.begin(9600);

  pinMode(CSPIN,OUTPUT);

  Serial.print("\nInitializing SD card...");

  // we'll use the initialization code from the utility libraries
  // since we're just testing if the card is working!
  if (!card.init(SPI_HALF_SPEED, CSPIN, WISHBONESLOT)) {
    Serial.println("initialization failed. Things to check:");
    Serial.println("* is a card is inserted?");
    Serial.println("* Is your wiring correct?");
    Serial.println("* did you change the chipSelect pin to match your shield or module?");
    return;
  } else {
   Serial.println("Wiring is correct and a card is present."); 
  }

}


void loop(void) {
 
  Serial.println("\n\nStarting Card Info:");
  // print the type of card
  Serial.print("Card type: ");
  switch(card.type()) {
    case SD_CARD_TYPE_SD1:
      Serial.println("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.println("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.println("SDHC");
      break;
    default:
      Serial.println("Unknown");
  }

  // Now we will try to open the 'volume'/'partition' - it should be FAT16 or FAT32
  if (!volume.init(card)) {
    Serial.println("Could not find FAT16/FAT32 partition.\nMake sure you've formatted the card");
    return;
  }


  // print the type and size of the first FAT-type volume
  uint32_t volumesize;
  Serial.print("\nVolume type is FAT");
  Serial.println(volume.fatType(), DEC);
  Serial.println();
  
  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                            // SD card blocks are always 512 bytes
  Serial.print("Volume size (bytes): ");
  Serial.println(volumesize);
  Serial.print("Volume size (Kbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  Serial.print("Volume size (Mbytes): ");
  volumesize /= 1024;
  Serial.println(volumesize);
  
  Serial.println("Card Info complete, waiting 5 seconds.");
  delay(5000);
  
}
