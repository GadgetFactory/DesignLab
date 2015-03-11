#include "SPIADC.h"

void SPIADC::begin(CS SEL, WISHBONESLOT wishboneSlot, ADCBITS bits)
{

 SPI_ADC_CS   = SEL;
 adcBits = bits;

 //SPI.begin(WishboneSlot(wishboneSlot_));
 SPI.begin();

 pinMode            (SPI_ADC_CS , OUTPUT);
 digitalWrite       (SPI_ADC_CS , HIGH);


//SPI.setBitOrder     (MSBFIRST);
SPI.setDataMode     (SPI_MODE3);
SPI.setClockDivider (SPI_CLOCK_DIV1024);


}

uint16_t SPIADC::read (byte pin)
{
uint16_t data ;
digitalWrite (SPI_ADC_CS , LOW);

// 0000 0XXX
// 00XX X000

pin = pin << 3 ;
SPI.transfer(pin);
//reach 16 rising edge
SPI.transfer(0);
//last 8 bits
data  = SPI.transfer(0);
data  = data << 8;
data |= SPI.transfer(0);

digitalWrite(SPI_ADC_CS,HIGH);

if ( adcBits ) return data  ; // 12 bit
else       return (data >> 4) ; //  8 bit

}


SPIADC analog ;
SPIADC analog1 ;
