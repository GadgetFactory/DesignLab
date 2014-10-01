/*!
 *  @file		APU2A03.cpp
 *  Project		APU2A03 Library
 *	@brief		APU2A03 Library for the ZPUino
 *	Version		1.0
 *  @author		Tim Gillespie 
 *	@date		12/10/12
 *  License		GPL
 */
#include "APU2A03.h"

#define APU2A03REG(x) REGISTER(apubase,x)

const int APU2A03::MIDI2freq[129] = {//MIDI note number
  0,0,0,0,0,0,0,0,//0-7
  0,0,0,0,0,0,0,0,//8-15
  0,0,0,0,0,0,0,0,//16-23
  0,0,0,0,0,0,0,0,//24-31
  0,2019,1906,1799,1698,1602,1512,1427,
  1347,1272,1200,1133,1069,1009,952,899,
  848,801,756,713,673,635,600,566,
  534,504,476,449,424,400,377,356,
  336,317,299,282,267,252,237,224,
  211,199,188,178,168,158,149,141,
  133,125,118,111,105,99,94,88,
  83,79,74,70,66,62,59,55,
  52,49,46,44,41,39,37,34,
  32,31,29,27,26,24,23,21,
  20,19,18,17,16,15,14,13,
  12,12,11,10,10,9,8,8,
  0//off
};

const int APU2A03::lengthtable[26]= {
0x03,
0x05,
0x07,
0x09,
0x0B,
0x0D,
0x0F,
0x11,
0x13,
0x15,
0x17,
0x19,
0x1B,
0x1D,
0x1F,
0x01,
0x0E,
0x04,
0x14,
0x0A,
0x1A,
0x06,
0x16,
0x08,
0x18,
0x01
};

void APUPulseVoice::setBase(int reg1address, int reg2address, int reg3address, int reg4address, unsigned int wishboneSlot)
{
	apubase = IO_SLOT(wishboneSlot);
    APU_ADDR_PULSE_1=reg1address;
	APU_ADDR_PULSE_2=reg2address;
	APU_ADDR_PULSE_3=reg3address;
	APU_ADDR_PULSE_4=reg4address;
}

void APUPulseVoice::setNote(int note, boolean active)
{
  APU2A03REG(APU_ADDR_PULSE_3) = APU2A03::MIDI2freq[note];
  APU_REG_PULSE_4.TIMER_HI = (APU2A03::MIDI2freq[note] >> 8);
  APU2A03REG(APU_ADDR_PULSE_4) = *(char*)&APU_REG_PULSE_4;
  currentFreq = APU2A03::MIDI2freq[note];
  APU2A03REG(APU_ADDR_FRAMECOUNTER) =0xff;
  if (active) {
	setVolume(volume);
	setDuty(duty);
	channel_active = 1;
	}	
	else 
	{
	setVolume(0x00);
	channel_active = 0;
	};
}


void APUPulseVoice::setDuty(int duty)
{
	APU_REG_PULSE_1.DUTY = duty;
	APU2A03REG(APU_ADDR_PULSE_1) = *(char*)&APU_REG_PULSE_1;
	//Serial.println(*(char*)&APU_REG_PULSE_1);
}

void APUPulseVoice::setEnvLoop(boolean active)
{
	APU_REG_PULSE_1.ENV_LOOP = active;
	APU2A03REG(APU_ADDR_PULSE_1) = *(char*)&APU_REG_PULSE_1;
}

void APUPulseVoice::setConstVol(boolean active)
{
	APU_REG_PULSE_1.CONST_VOL = active;
	APU2A03REG(APU_ADDR_PULSE_1) = *(char*)&APU_REG_PULSE_1;
}

void APUPulseVoice::setVolume(int volume)
{
	APU_REG_PULSE_1.VOLUME = volume;
	APU2A03REG(APU_ADDR_PULSE_1) = *(char*)&APU_REG_PULSE_1;
}

void APUPulseVoice::setSweepEnable(boolean active)
{
	APU_REG_PULSE_2.SWEEP_EN = active;
	APU2A03REG(APU_ADDR_PULSE_2) = *(char*)&APU_REG_PULSE_2;
}
void APUPulseVoice::setSweepPeriod(int sweep_period)
{
	APU_REG_PULSE_2.SWEEP_PERIOD = sweep_period;
	APU2A03REG(APU_ADDR_PULSE_2) = *(char*)&APU_REG_PULSE_2;
}
void APUPulseVoice::setSweepDirection(boolean active)
{
	APU_REG_PULSE_2.SWEEP_DIRECTION = active;
	APU2A03REG(APU_ADDR_PULSE_2) = *(char*)&APU_REG_PULSE_2;
}
void APUPulseVoice::setSweepShift(int sweep_shift)
{
	APU_REG_PULSE_2.SWEEP_SHIFT = sweep_shift;
	APU2A03REG(APU_ADDR_PULSE_2) = *(char*)&APU_REG_PULSE_2;
}
void APUPulseVoice::setTimerLo(int timer_lo)
{
}

void APUPulseVoice::setLengthCounter(int length_counter)
{
	
	APU_REG_PULSE_4.LENGTH_COUNTER = APU2A03::lengthtable[length_counter];
	APU2A03REG(APU_ADDR_PULSE_4) = *(char*)&APU_REG_PULSE_4;
}
void APUPulseVoice::setTimerHi(int timer_hi)
{
}
void APUPulseVoice::reset() 
{
  //set frequency to no freq
  //setNote(128,true);   

  //
  APU_REG_PULSE_1.DUTY = 0;  
  APU_REG_PULSE_1.ENV_LOOP = 0;  
  APU_REG_PULSE_1.CONST_VOL = 1;
  APU_REG_PULSE_1.VOLUME = 0;  
  
  APU_REG_PULSE_2.SWEEP_EN = 0;  
  APU_REG_PULSE_2.SWEEP_PERIOD = 0;  
  APU_REG_PULSE_2.SWEEP_DIRECTION = 0;
  APU_REG_PULSE_2.SWEEP_SHIFT = 0;  
  
  APU_REG_PULSE_3 = 0;
  
  APU_REG_PULSE_4.LENGTH_COUNTER = 0;  
  APU_REG_PULSE_4.TIMER_HI = 0;
   
  APU2A03REG(APU_ADDR_PULSE_1) = *(char*)&APU_REG_PULSE_1;
  APU2A03REG(APU_ADDR_PULSE_2) = *(char*)&APU_REG_PULSE_2;
  APU2A03REG(APU_ADDR_PULSE_3) = *(char*)&APU_REG_PULSE_3;
  APU2A03REG(APU_ADDR_PULSE_4) = *(char*)&APU_REG_PULSE_4;
  
  volume=0xff;
}
void APUPulseVoice::handleCC(byte number, byte value)
{
switch (number) {  
    case 0:
		setSweepPeriod(value >> 4);
		break;
    case 1:
		setSweepDirection(value >> 6);
		break;
    case 2:
		setSweepShift(value >> 4);
		break;		
    case 3:
		duty = value >> 5;
		if (channel_active) setDuty(duty);
		break;
    case 4	:
		setEnvLoop(value >> 5);
		break;
    case 6:
		setSweepEnable(value >> 6);
		break;
    case 7:
		volume = value >> 3;
		break;
    case 8:
		setConstVol(value >> 6);
		break;
	case 20:
		setLengthCounter(value);
		break;
	default:
      return;
      break;       
  } 
}
void APUTriVoice::setBase(int wishboneSlot)
{
	apubase = IO_SLOT(wishboneSlot);
}

void APUTriVoice::setNote(int note, boolean active)
{
  APU2A03REG(APU_ADDR_TRIANGLE_2) = APU2A03::MIDI2freq[note];
  APU_REG_TRIANGLE_3.TIMER_HI = (APU2A03::MIDI2freq[note] >> 8);
  APU2A03REG(APU_ADDR_TRIANGLE_3) = *(char*)&APU_REG_TRIANGLE_3;
  currentFreq = APU2A03::MIDI2freq[note];
    if (active) {
//	setLengthCounterHalt(1);
	APU2A03REG(APU_ADDR_FRAMECOUNTER) =0xff;
	setLinearCounter(linear);
	setLengthCounter(length);
	}	
	else 
	{
	APU2A03REG(APU_ADDR_TRIANGLE_1) =0x00;
	setLinearCounter(0x00);
	setLengthCounter(0x00);
	APU2A03REG(APU_ADDR_FRAMECOUNTER) =0xff;
	};
}

void APUTriVoice::setLengthCounterHalt( boolean active)
{
	APU_REG_TRIANGLE_1.LCHALT = active;
	APU2A03REG(APU_ADDR_TRIANGLE_1) = *(char*)&APU_REG_TRIANGLE_1;
}

void APUTriVoice::setLinearCounter( int linear_counter)
{
	APU_REG_TRIANGLE_1.LINEARCOUNTER = linear_counter;
	APU2A03REG(APU_ADDR_TRIANGLE_1) = *(char*)&APU_REG_TRIANGLE_1;
}

void APUTriVoice::setTimerLo(int timer_lo)
{
}

void APUTriVoice::setLengthCounter(int length_counter)
{
	APU_REG_TRIANGLE_3.LENGTHCOUNTER = length_counter;
	APU2A03REG(APU_ADDR_TRIANGLE_3) = *(char*)&APU_REG_TRIANGLE_3;
}

void APUTriVoice::setTimerHi(int timer_hi)
{
}

void APUTriVoice::reset()
{
	APU_REG_TRIANGLE_1.LCHALT =1;
    APU_REG_TRIANGLE_1.LINEARCOUNTER = 0; 
	APU_REG_TRIANGLE_2 = 0;
	APU_REG_TRIANGLE_3.LENGTHCOUNTER = 0;
	APU_REG_TRIANGLE_3.TIMER_HI = 0;
	
	linear = 0xff;
	length = 0xff;
	
	APU2A03REG(APU_ADDR_TRIANGLE_1) = *(char*)&APU_REG_TRIANGLE_1;
	APU2A03REG(APU_ADDR_TRIANGLE_2) = *(char*)&APU_REG_TRIANGLE_2;
	APU2A03REG(APU_ADDR_TRIANGLE_3) = *(char*)&APU_REG_TRIANGLE_3;
}

void APUTriVoice::handleCC(byte number, byte value)
{
switch (number) {  
    case 4:
		setLengthCounterHalt(value >> 6);
		break;		
	case 20:
		length = value;
		break;
	case 22:
		linear = value;
	default:
      return;
      break;       
  }
}

void APUNoiseVoice::setBase(int wishboneSlot)
{
	apubase = IO_SLOT(wishboneSlot);
}

void APUNoiseVoice::setNote(int pitch, boolean active)
{
APU_REG_NOISE_2.PERIOD = pitch >> 3;
APU2A03REG(APU_ADDR_NOISE_2) = *(char*)&APU_REG_NOISE_2;
currentFreq = APU2A03::MIDI2freq[pitch];
  if (active) {
	setVolume(volume);
	setLengthCounter(length<<2);
	APU2A03REG(APU_ADDR_FRAMECOUNTER) =0xff;
	}	
	else 
	{
	setVolume(0x00);
	};
}

void APUNoiseVoice::setLengthCounterHalt( boolean active)
{
	APU_REG_NOISE_1.LCHALT = active;
	APU2A03REG(APU_ADDR_NOISE_1) = *(char*)&APU_REG_NOISE_1;
}
void APUNoiseVoice::setConstantVolume( boolean active)
{
	APU_REG_NOISE_1.CONST_VOL = active;
	APU2A03REG(APU_ADDR_NOISE_1) = *(char*)&APU_REG_NOISE_1;
}
void APUNoiseVoice::setVolume(int volume)
{
	APU_REG_NOISE_1.VOLUME = volume;
	APU2A03REG(APU_ADDR_NOISE_1) = *(char*)&APU_REG_NOISE_1;
}
void APUNoiseVoice::setLoopNoise(boolean active)
{
	APU_REG_NOISE_2.LOOPNOISE = active;
	APU2A03REG(APU_ADDR_NOISE_2) = *(char*)&APU_REG_NOISE_2;
}
void APUNoiseVoice::setLengthCounter(int length_counter)
{
	APU_REG_NOISE_3 = length_counter;
	APU2A03REG(APU_ADDR_NOISE_3) = *(char*)&APU_REG_NOISE_3;	
}
void APUNoiseVoice::setPeriod(int period)
{
	APU_REG_NOISE_2.PERIOD = period;
	APU2A03REG(APU_ADDR_NOISE_2) = *(char*)&APU_REG_NOISE_2;
}
void APUNoiseVoice::reset()
{	
	length = 0xff;
	volume = 0xff;
    APU_REG_NOISE_1.EMPTY=0;
    APU_REG_NOISE_1.LCHALT = 1;
	APU_REG_NOISE_1.CONST_VOL = 1;
	APU_REG_NOISE_1.VOLUME = 0x0;
    
	APU_REG_NOISE_2.LOOPNOISE = 0;
	APU_REG_NOISE_2.EMPTY = 0;
	APU_REG_NOISE_2.PERIOD = 0;
	
	APU_REG_NOISE_3 = 0;
	
	APU2A03REG(APU_ADDR_NOISE_1) = *(char*)&APU_REG_NOISE_1;
	APU2A03REG(APU_ADDR_NOISE_2) = *(char*)&APU_REG_NOISE_2;
	APU2A03REG(APU_ADDR_NOISE_3) = *(char*)&APU_REG_NOISE_3;
}

void APUNoiseVoice::handleCC(byte number, byte value)
{
switch (number) {  
    case 1:
		setLoopNoise(value >> 6);
		break;
    case 4:
		setLengthCounterHalt(value >> 6);
		break;		
    case 8:
		setConstantVolume(value >> 6);
		break;
	case 20:
		//setLengthCounter(value);
		break;
	case 21:
		volume = value;
	default:
      return;
      break;       
  }
}  

	
void APU2A03::setup(unsigned int wishboneSlot)
{
	apubase = IO_SLOT(wishboneSlot);
	P1.setBase(APU_ADDR_PULSE1_1, APU_ADDR_PULSE1_2, APU_ADDR_PULSE1_3, APU_ADDR_PULSE1_4, wishboneSlot);
	P2.setBase(APU_ADDR_PULSE2_1, APU_ADDR_PULSE2_2, APU_ADDR_PULSE2_3, APU_ADDR_PULSE2_4, wishboneSlot);
	Tri.setBase(wishboneSlot);
	Noise.setBase(wishboneSlot);
	reset();
}
void APU2A03::writeData(unsigned char address, unsigned char data)
{
	APU2A03REG(address) = data;
}      
void APU2A03::reset()
{
  P1.reset();
  P2.reset();
  Tri.reset();
  Noise.reset();
  
  APU_REG_STATUS.EMPTY = 0;
  APU_REG_STATUS.DMC_EN = 0;
  APU_REG_STATUS.NOISE_EN = 0;
  APU_REG_STATUS.TRI_EN = 0;
  APU_REG_STATUS.P2_EN= 0;
  APU_REG_STATUS.P1_EN = 1;
  
  APU2A03REG(APU_ADDR_STATUS) = *(char*)&APU_REG_STATUS;
  
}
