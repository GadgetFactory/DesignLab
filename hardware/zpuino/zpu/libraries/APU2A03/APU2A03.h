/*!
 *  @file		APU2A03.h
 *  Project		APU2A03 Library
 *	@brief		APU2A03 Library for the ZPUino
 *	Version		1.0
 *  @author		Tim Gillespie 
 *	@date		12/5/13
 *  License		GPL
 */

#ifndef LIB_APU2A03_H_
#define LIB_APU2A03_H_

#include <inttypes.h> 
#include <zpuino-types.h>
#include <zpuino.h>
#include "Arduino.h"


#define APU_ADDR_PULSE1_1 0x00
#define APU_ADDR_PULSE1_2 0x01
#define APU_ADDR_PULSE1_3 0x02
#define APU_ADDR_PULSE1_4 0x03

#define APU_ADDR_PULSE2_1 0x04
#define APU_ADDR_PULSE2_2 0x05
#define APU_ADDR_PULSE2_3 0x06
#define APU_ADDR_PULSE2_4 0x07

#define APU_ADDR_TRIANGLE_1 0x08
#define APU_ADDR_TRIANGLE_2 0x0A
#define APU_ADDR_TRIANGLE_3 0x0B

#define APU_ADDR_NOISE_1 0x0C
#define APU_ADDR_NOISE_2 0x0E
#define APU_ADDR_NOISE_3 0x0F

#define APU_ADDR_DMC_1 0x0F
#define APU_ADDR_DMC_2 0x0F
#define APU_ADDR_DMC_3 0x0F
#define APU_ADDR_DMC_4 0x0F

#define APU_ADDR_STATUS 0x15

#define APU_ADDR_FRAMECOUNTER 0x17



class APUPulseVoice
{ 
  public:
    void setBase(int reg1address, int reg2address, int reg3address, int reg4adress, unsigned int wishboneSlot);
    void setNote(int note, boolean active);
	
	void setDuty(int duty);
	void setEnvLoop(boolean active);
	void setConstVol(boolean active);
	void setVolume(int volume);
	void setSweepEnable(boolean active);
	void setSweepPeriod(int sweep_period);
	void setSweepDirection(boolean active);
	void setSweepShift(int sweep_shift);
	void setTimerLo(int timer_lo);
	void setLengthCounter(int length_counter);
	void setTimerHi(int timer_hi);

    void reset(); 
    void handleCC(byte number, byte value); 
     
  private:
	unsigned int apubase;
    int baseAddress;
    int currentFreq;
	int volume;
	int duty;
	boolean channel_active;
    int APU_ADDR_PULSE_1;
	int APU_ADDR_PULSE_2;
	int APU_ADDR_PULSE_3;
	int APU_ADDR_PULSE_4;
    
    struct APU_REG_PULSE_1_STRUCT{
        unsigned int DUTY : 2;
        unsigned int ENV_LOOP : 1; 
        unsigned int CONST_VOL : 1;
		unsigned int VOLUME : 4;
    } ;  
	struct APU_REG_PULSE_2_STRUCT{
		unsigned int SWEEP_EN : 1;
		unsigned int SWEEP_PERIOD : 3;
		unsigned int SWEEP_DIRECTION : 1;
		unsigned int SWEEP_SHIFT : 3;
	} ;
	struct APU_REG_PULSE_4_STRUCT{
		unsigned int LENGTH_COUNTER : 5;
		unsigned int TIMER_HI : 3;
	} ;
    APU_REG_PULSE_1_STRUCT APU_REG_PULSE_1;
	APU_REG_PULSE_2_STRUCT APU_REG_PULSE_2;
	unsigned int APU_REG_PULSE_3;
	APU_REG_PULSE_4_STRUCT APU_REG_PULSE_4;
	
};

class APUTriVoice
{ 
  public:
    //void setBase(int reg1address, int reg2address, int reg3address, unsigned int wishboneSlot);
	void setBase(int wishboneSlot);
    void setNote(int note, boolean active);
	
	void setLengthCounterHalt( boolean active);
	void setLinearCounter( int linear_counter);
	void setTimerLo(int timer_lo);
	void setLengthCounter(int length_counter);
	void setTimerHi(int timer_hi);

    void reset(); 
    void handleCC(byte number, byte value); 
     
  private:
	unsigned int apubase;
    int baseAddress;
    int currentFreq;
	int length;
	int linear;
    
    struct APU_REG_TRIANGLE_1_STRUCT{
        unsigned int LCHALT : 1;
        unsigned int LINEARCOUNTER : 7; 
    } ;  
	struct APU_REG_TRIANGLE_3_STRUCT{
		unsigned int LENGTHCOUNTER : 5;
		unsigned int TIMER_HI : 3;
	} ;
	APU_REG_TRIANGLE_1_STRUCT APU_REG_TRIANGLE_1;
	APU_REG_TRIANGLE_3_STRUCT APU_REG_TRIANGLE_3;
	unsigned int APU_REG_TRIANGLE_2;
	
	
};

class APUNoiseVoice
{ 
  public:
    //void setBase(int reg1address, int reg2address, int reg3address, unsigned int wishboneSlot);
	void setBase(int wishboneSlot);
    void setNote(int note, boolean active);
	
	void setLengthCounterHalt( boolean active);
	void setConstantVolume( boolean active);
	void setVolume(int volume);
	void setLoopNoise(boolean active);
	void setLengthCounter(int length_counter);
	void setPeriod(int period);

    void reset(); 
    void handleCC(byte number, byte value); 
     
  private:
	unsigned int apubase;
    int baseAddress;
    int currentFreq;
	int volume;
	int length;
    
    struct APU_REG_NOISE_1_STRUCT{
        unsigned int EMPTY : 2;
        unsigned int LCHALT : 1;
		unsigned int CONST_VOL : 1;
		unsigned int VOLUME : 4;
    } ;  
	struct APU_REG_NOISE_2_STRUCT{
		unsigned int LOOPNOISE : 1;
		unsigned int EMPTY : 3;
		unsigned int PERIOD : 4;
	} ;
	APU_REG_NOISE_1_STRUCT APU_REG_NOISE_1;
	APU_REG_NOISE_2_STRUCT APU_REG_NOISE_2;
	unsigned int APU_REG_NOISE_3;
	
	
};

class APU2A03
{
  public:
    APUPulseVoice P1;
    APUPulseVoice P2;
	APUTriVoice Tri;
	APUNoiseVoice Noise;
   
 //   APU2A03();
	void setup(unsigned int wishboneSlot);
    void writeData(unsigned char address, unsigned char data);      
    void reset();    
    static const int MIDI2freq[129];
	static const int lengthtable[26];
  private:
	unsigned int apubase;
	struct APU_REG_STATUS_STRUCT{
		unsigned int EMPTY : 3;
		unsigned int DMC_EN : 1;
		unsigned int NOISE_EN : 1;
		unsigned int TRI_EN : 1;
		unsigned int P2_EN : 1;
		unsigned int P1_EN : 1;
	};
	APU_REG_STATUS_STRUCT APU_REG_STATUS;
};
#endif // LIB_APU2A03_H_
