#include "SevenSegHW.h"

static unsigned char table7seg[16] =
{
    0x3F, //0011 1111, 0
    0x06, //0000 0110, 1
    0x5B, //0101 1011  2
    0x4F, //0100 1111  3
    0x66, //0110 0110  4
    0x6D, //0110 1101  5
    0x7D, //0111 1101  6
    0x07, //0000 0111  7
    0x7F, //0111 1111  8
    0x6F, //0110 1111  9
    0x77, //0111 0111  A
    0x7C, //0110 1110  B
    0x39, //0011 1001  C
    0x5E, //0101 1110  D
    0x79, //0111 1001  E
    0x71  //0111 0001  F
};

static int int_to_7seg(int v)
{
    return table7seg[v%16];
}


// Default Constructor
SEVENSEGHW::SEVENSEGHW()
{
}

void SEVENSEGHW::begin(int wishboneSlot)
{
	this->wishboneSlot = wishboneSlot;
}

// Set the 4 digits Int value
void SEVENSEGHW::setIntValue(unsigned int value, unsigned int pos_dot)
{
    REGISTER( IO_SLOT(wishboneSlot), 7 ) = int_to_7seg( value      %10) | (pos_dot==4 ? 0x80:0x00);
    REGISTER( IO_SLOT(wishboneSlot), 6 ) = int_to_7seg((value/10  )%10) | (pos_dot==3 ? 0x80:0x00);
    REGISTER( IO_SLOT(wishboneSlot), 5 ) = int_to_7seg((value/100 )%10) | (pos_dot==2 ? 0x80:0x00);
    REGISTER( IO_SLOT(wishboneSlot), 4 ) = int_to_7seg((value/1000)%10) | (pos_dot==1 ? 0x80:0x00);
}

// Set a digit value
void SEVENSEGHW::setDigitValue(unsigned int value, unsigned int dot, unsigned int digit)
{
    REGISTER( IO_SLOT(wishboneSlot), (4 + digit) ) = int_to_7seg(value%10) | (dot==1 ? 0x80:0x00);

}

// Set 16 bits Hex value
void SEVENSEGHW::setHexValue(unsigned int value)
{
    REGISTER( IO_SLOT(wishboneSlot), 7 ) = int_to_7seg( value            %16) ;
    REGISTER( IO_SLOT(wishboneSlot), 6 ) = int_to_7seg((value/16        )%16) ;
    REGISTER( IO_SLOT(wishboneSlot), 5 ) = int_to_7seg((value/(16*16)   )%16) ;
    REGISTER( IO_SLOT(wishboneSlot), 4 ) = int_to_7seg((value/(16*16*16))%16) ;
}

// Get the 4 digits Int value
unsigned int SEVENSEGHW::getIntValue()
{
    return REGISTER( IO_SLOT(wishboneSlot), 7 ) + (REGISTER( IO_SLOT(wishboneSlot), 6 ) *10) + (REGISTER( IO_SLOT(wishboneSlot), 5 ) *100) + (REGISTER( IO_SLOT(wishboneSlot), 4 ) *1000)   ;
	//return SEVSEGDIGITO + (SEVSEGDIGIT1 *10) + (SEVSEGDIGIT2 *100) + (SEVSEGDIGIT3 *1000)   ;
}


// Get a digit value
unsigned int SEVENSEGHW::getDigitValue(unsigned int digit)
{
    return REGISTER( IO_SLOT(wishboneSlot), 4+ digit );
}

// Get Dot position
unsigned int SEVENSEGHW::getDotPosition()
{
    if ((REGISTER( IO_SLOT(wishboneSlot), 7 ) & 0x80) == 0x80)
    {
        return 1;
    } else if ((REGISTER( IO_SLOT(wishboneSlot), 6 ) & 0x80) == 0x80)
    {
        return 2;
    } else if ((REGISTER( IO_SLOT(wishboneSlot), 5 ) & 0x80) == 0x80)
    {
        return 3;
    } else if ((REGISTER( IO_SLOT(wishboneSlot), 4 ) & 0x80) == 0x80)
    {
        return 4;
    }

    return 0;
}

// Set a Hexadecimal value
void SEVENSEGHW::setHexValue(unsigned int value, unsigned int digit)
{
    REGISTER( IO_SLOT(wishboneSlot), (4 + digit) ) = int_to_7seg(value%16) ;

}

// Set a Custom value
void SEVENSEGHW::custom(unsigned int value, unsigned int digit)
{
    REGISTER( IO_SLOT(wishboneSlot), (4 + digit) ) = value ;

}

// Set Brightness
void SEVENSEGHW::setBrightness(unsigned int value)
{
    //SEVSEGBRIGHT = (value << 4 )| getSegmentStatus();
	//SEVSEGBRIGHT = (0xE000F);
	REGISTER( IO_SLOT(wishboneSlot), 0 ) = (0xF | (value<<16));
}

// Get Brightness
unsigned int SEVENSEGHW::getBrightness()
{
    return REGISTER( IO_SLOT(wishboneSlot), 0 ) >> 4 ;
}

// Set Extra value
void SEVENSEGHW::setExtra(unsigned int value)
{
    REGISTER( IO_SLOT(wishboneSlot), 1 ) = value;
}

// Get Extra value
unsigned int SEVENSEGHW::getExtra()
{
    return REGISTER( IO_SLOT(wishboneSlot), 1 ) ;
}

// enable/disable segment
void SEVENSEGHW::setSegmentStatus(unsigned int enabled)
{
    REGISTER( IO_SLOT(wishboneSlot), 0 ) = enabled & 0xF | (getBrightness() << 4);
}

unsigned int SEVENSEGHW::getSegmentStatus()
{
    return REGISTER( IO_SLOT(wishboneSlot), 0 ) & 0xF ;
}



