#include "PLL.h"

#define PLLBASE_REG(x) REG((x))  
#define PLLCONF_REG(x) REG((x)+32)  
#define PLLCONF_DAT(x) REG((x)+48)  
#define ADVPLLREG(x)   REG((x)+64)  

#define PLLSTAT              PLLBASE_REG(0)
#define PLLCONF_CLKFBOUT     PLLBASE_REG(1)
#define PLLCONF_DIGITALFILT  PLLBASE_REG(2)
#define PLLCONF_LOCK         PLLBASE_REG(3)
#define PLLCONF_CLKOUT0      PLLBASE_REG(4)


union pll_conf {
    struct {
        uint16_t pad:2;
        uint16_t edge:1;
        uint16_t nocount:1;
        uint16_t high_time:6;
        uint16_t low_time:6;
    } r;
    uint16_t v;
};

static const unsigned s6_pll_lock_lookup[] = {
    0x00049fe8,
    0x00049fe8,
    0x0006afe8,
    0x000943e8,
    0x000b53e8,
    0x000d63e8,
    0x000ff7e8,
    0x000ff7e8,
    0x000ff7e8,
    0x000ff7e8,
    0x000ff784,
    0x000ff739,
    0x000ff6ee,
    0x000ff6bc,
    0x000ff68a,
    0x000ff671,
    0x000ff63f,
    0x000ff626,
    0x000ff60d,
    0x000ff5f4,
    0x000ff5db,
    0x000ff5c2,
    0x000ff5a9,
    0x000ff590,
    0x000ff590,
    0x000ff577,
    0x000ff55e,
    0x000ff55e,
    0x000ff545,
    0x000ff545,
    0x000ff52c,
    0x000ff52c,
    0x000ff52c,
    0x000ff513,
    0x000ff513,
    0x000ff513,
    0x000ff4fa
};

static const unsigned s6_pll_filter_lookup[] = {
    0x000bcb71,
    0x000fd7b1,
    0x000bd871,
    0x000ff9b1,
    0x000bfab1,
    0x000dfb31,
    0x0003ff31,
    0x0005ff31,
    0x0009fcb1,
    0x000ef8b1,
    0x000efd31,
    0x0001fd31,
    0x0001fd31,
    0x0006f931,
    0x0006f931,
    0x000af931,
    0x000af931,
    0x000afd31,
    0x000afd31,
    0x000afd31,
    0x000afd31,
    0x000cf631,
    0x000cf631,
    0x000cfa31,
    0x000cfa31,
    0x000cfe31,
    0x000cfe31,
    0x000cfe31,
    0x000cfe31,
    0x000cfe31,
    0x0002fa31,
    0x0002fa31,
    0x000cfe31,
    0x000cfe31,
    0x0002f532,
    0x0002f532,
    0x0004fd32,
    0x0002f132,
    0x0002f132,
    0x0002f132,
    0x0008d132,
    0x0008d132,
    0x0008d132,
    0x0004d632,
    0x0002de32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0008ce32,
    0x0004ce32,
    0x0004ce32,
    0x0004ce32,
    0x0004ce32,
    0x0004ce32,
    0x0004ce32,
    0x0004ce32,
    0x0004ce32
};

// This returns LockRefDly + LockFBDly + LockCnt
// LockSatHigh + UnlockCnt are constant 0xFA401
static unsigned s6_pll_get_lock(unsigned divide)
{
    divide--;
    if (divide>36)
        divide=36;
    return s6_pll_lock_lookup[divide];
}
static unsigned s6_pll_get_filter(unsigned divide, int highbw)
{
    divide--;
    unsigned v = s6_pll_filter_lookup[divide];
    if (highbw)
        return v>>10;
    return v&((1<<10)-1);
}

static int pll_divider(uint8_t divide, pll_conf *dest)
{
    dest->r.edge=0;
    if (divide==1) {
        dest->r.nocount=1;
        dest->r.low_time=1;
        dest->r.high_time=1;
        return 0;
    }
    dest->r.nocount=0;

    dest->r.high_time = divide>>1;
    dest->r.low_time = divide>>1;

    if (divide&1) {
        dest->r.edge=1;
        dest->r.low_time++;
    }
    return 0;
}

void PLL_class::pll_apply_register( int reg, unsigned val, unsigned mask)
{
    unsigned v = ADVPLLREG(reg);
    v&=mask;
    v|=(val&(~mask));
    ADVPLLREG(reg) = v;
}

int PLL_class::set(unsigned mult, unsigned div)
{
    union pll_conf conf_mult, conf_div;
    int i;
    unsigned vco = 42*mult;
#ifdef PLL_DEBUG
    printf("Requested PLL configuration: %uHKz, mult %d, div %d (VCO %uMHZ)\r\n",
           (vco*1000)/div,
           mult,div,vco
          );
#endif
    if ((vco<400) || (vco>1000)) {
#ifdef PLL_DEBUG
        printf("VCO out of range, not applying\r\n");
#endif
        return -1;
    }

    pll_divider(div, &conf_div);
    pll_divider(mult, &conf_mult);
    // Multiplier
    PLLCONF_CLKFBOUT = conf_mult.v;
    // Divider
    PLLCONF_CLKOUT0  = conf_div.v;
    // Filter
    PLLCONF_DIGITALFILT = s6_pll_get_filter(div, false);
    // Lock
    PLLCONF_LOCK = s6_pll_get_lock(div);
    // Put PLL in reset mode
    PLLSTAT = 1;
    unsigned s = PLLSTAT;
    if ((s&1)==0) {
#ifdef PLL_DEBUG
        printf("Cannot put PLL in reset mode ? status: 0x%08x\r\n",s);
#endif
    }
    for (i=0;i<16;i++) {
        // First, get the PLL_ADV register number for the sequence.
        unsigned pllreg = PLLCONF_REG(i) & 0xff;
        if (pllreg==0)
            break;
        // Get data and mask;
        unsigned plldata = PLLCONF_DAT(i);
        unsigned pllmask = plldata>>16;
        plldata &= 0xffff;
        // Debug only
        //printf("Apply reg 0x%02x: 0x%04x mask 0x%04x\r\n", pllreg, plldata, pllmask);
        pll_apply_register(pllreg,plldata,pllmask);
    }
    //printf("Relinquising PLL from RESET...\r\n");
    PLLSTAT  = 0;
#ifdef PLL_DEBUG
    printf("Waiting for PLL to lock... ");
#endif
    int tries = 10;
    while (tries--) {
        unsigned s = PLLSTAT;
        if (s&2) {
#ifdef PLL_DEBUG
            printf("locked.\r\n");
#endif
            break;
        }
        delay(10);
    }
    if (tries==0) {
#ifdef PLL_DEBUG
        printf("could not lock PLL: status 0x%08x\r\n", (unsigned)PLLSTAT);
#endif
        return -1;
    }
    return 0;
}

int PLL_class::begin()
{
    if (deviceBegin(0x08,0x1E)!=0)
        return -1;
    return 0;
}

int PLL_class::begin(register_t base)
{
    return BaseDevice::deviceBegin(base);
}
