/*

 Computing_Shield - Summarize your library here.

 Describe your library here.

 License: GNU General Public License V3

 (C) Copyright (Your Name Here)
 
 For more help on how to make an Arduino style library:
 http://arduino.cc/en/Hacking/LibraryTutorial

 */

#include "Arduino.h"
#include "Computing_Shield.h"

Computing_Shield::Computing_Shield()
{

}

void Computing_Shield::setup(unsigned int wishboneSlot)
{
	this->wishboneSlot = wishboneSlot;
}

unsigned long Computing_Shield::readButtons()
{
	return REGISTER(IO_SLOT(wishboneSlot),1);
}

void Computing_Shield::writeLEDs(unsigned long value)
{
	REGISTER(IO_SLOT(wishboneSlot),0) = value;
}
