#ifndef __PLL_H__
#define __PLL_H__

#include "Arduino.h"

using namespace ZPUino;

#define PLL_ERROR 0xffffffff

class PLL_class: public BaseDevice
{
public:
    PLL_class(uint8_t instance=1): BaseDevice(instance) { iclk_khz = 42000; }
    int begin();
    int begin(register_t base);
    void setclkkhz(unsigned khz);
    unsigned getclkkhz()const{return iclk_khz;}
    int set(unsigned mult, unsigned div);
    int set(unsigned mult, unsigned div0, unsigned div1, unsigned div2);
    static void scanBest(unsigned base_khz, unsigned target_khz, unsigned *m, unsigned *d, unsigned *error);
protected:
    void pll_apply_register( int reg, unsigned val, unsigned mask);
    int reg_displacement;
    unsigned iclk_khz;
};

#endif
