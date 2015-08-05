#include <ZPUino_GFX.h>

const modeline_t modeline_640x480_60 =   {25175,640, 656,  752,800, 480, 490,  492, 525,1,1,0,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_320x240_60 =   {25175,640, 656,  752,800, 480, 490,  492, 525,1,1,1,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_800x600_60 =   {40000,800, 840,  968,1056,600, 601,  605, 628,0,0,0,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_400x300_60 =   {40000,800, 840,  968,1056,600, 601,  605, 628,0,0,1,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_1024x768_60 =  {65000,1024,1048,1184,1344,768, 771,  777, 806,1,1,0,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_512x384_60 =   {65000,1024,1048,1184,1344,768, 771,  777, 806,1,1,1,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_1280x768_60 =  {68250,1280,1328,1360,1440,768, 771,  778, 790,0,0,0,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_640x384_60 =   {68250,1280,1328,1360,1440,768, 771,  778, 790,0,0,1,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_1280x1024_60 = {108000,1280,1328,1440,1688,1024,1025,1028,1066,0,0,0,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_640x512_60 =   {108000,1280,1328,1440,1688,1024,1025,1028,1066,0,0,1,COMPAT_VGA|COMPAT_HDMI};
const modeline_t modeline_hdmi_720_480 = {27027, 720,  744,   784, 880, 480, 490,  493, 525,0,0,0,COMPAT_HDMI};
const modeline_t modeline_hdmi_1280_720 ={74250, 1280, 1352, 1432,1648, 720, 723,  728, 750,0,0,0,COMPAT_HDMI};

static const modeline_t all_modelines[] = {
    modeline_640x480_60,
    modeline_320x240_60,
    modeline_800x600_60,
    modeline_400x300_60,
    modeline_1024x768_60,
    modeline_512x384_60,
    modeline_1280x768_60,
    modeline_640x384_60,
    modeline_1280x1024_60,
    modeline_640x512_60,
    modeline_hdmi_720_480,
    modeline_hdmi_1280_720
};

static const modeline_t *scanModeline(unsigned w, unsigned h, unsigned compat)
{
    unsigned int i,cw,ch;
    for (i=0;i<sizeof(all_modelines)/sizeof(all_modelines[0]); i++) {
        const modeline_t *m = &all_modelines[i];
        if (!(m->compat & compat))
            continue;
        cw = m->hdisplay;
        ch = m->vdisplay;

        if (m->duplicate) {
            cw>>=1;
            ch>>=1;
        }
        if ((cw == w) && (ch == h)) {
            return m;
        }
    }
    return NULL;
}

template<>
int ZPUino_GFX_class<uint16_t>::setupVGA(const modeline_t *mode)
{
    unsigned pllm,plld,pllerror;
    // First, disable display output.

    REG(2)=0;
    uint32_t temp = mode->vpol << 1 || mode->hpol;
    if (mode->duplicate)
        temp|=0x8;

    // Now, setup VGA
    REG(3)  = temp;
    REG(8)  = mode->hdisplay;
    REG(9)  = mode->hsyncstart;
    REG(10) = mode->hsyncend;
    REG(11) = mode->htotal;
    REG(12) = mode->vdisplay;
    REG(13) = mode->vsyncstart;
    REG(14) = mode->vsyncend;
    REG(15) = mode->vtotal;

    if (pll.begin(getBaseRegister()+PLLOFFSET)!=0) {
        return -1;
    }

    PLL_class::scanBest( pll.getclkkhz(), mode->pixelclock, &pllm, &plld, &pllerror);

    if (pllerror==PLL_ERROR) {
        Serial.println("Cannot find a suitable PLL setting for mode");
        return -1;
    }

    if (pll.set(pllm, plld)==0) {
        // Enable display output again.
        REG(2)=1;
        if (mode->duplicate) {
            Adafruit_GFX_core<uint16_t>::begin(mode->hdisplay>>1,mode->vdisplay>>1);
        } else {
            Adafruit_GFX_core<uint16_t>::begin(mode->hdisplay,mode->vdisplay);
        }
        return 0;
    }
    return -1;
}

template<>
int ZPUino_GFX_class<uint16_t>::setupHDMI(const modeline_t *mode)
{
    unsigned pllm,plld,pllerror;
    // First, disable display output.
    REG(2)=0;
    uint32_t temp = mode->vpol << 1 || mode->hpol;
    if (mode->duplicate)
        temp|=0x8;
    Serial.println("Setting mode");
    // Now, setup VGA
    REG(3)  = temp;
    REG(8)  = mode->hdisplay;
    REG(9)  = mode->hsyncstart;
    REG(10) = mode->hsyncend;
    REG(11) = mode->htotal;
    REG(12) = mode->vdisplay;
    REG(13) = mode->vsyncstart;
    REG(14) = mode->vsyncend;
    REG(15) = mode->vtotal;

    if (pll.begin(getBaseRegister()+256)!=0) {
        Serial.println("Cannot find PLL??");
        return -1;
}

    pll.setclkkhz(22500);
    PLL_class::scanBest( pll.getclkkhz(), mode->pixelclock*10, &pllm, &plld, &pllerror);

    if (pllerror==PLL_ERROR) {
        Serial.println("Cannot find a suitable PLL setting for mode");
        return -1;
    }

    if (pll.set(pllm,
                plld,
                plld*5,
                plld*10
               )==0) {
            // Enable display output again.
        REG(2)=1;
        if (mode->duplicate) {
            Adafruit_GFX_core<uint16_t>::begin(mode->hdisplay>>1,mode->vdisplay>>1);
        } else {
            Adafruit_GFX_core<uint16_t>::begin(mode->hdisplay,mode->vdisplay);
        }
        return 0;
    }
    return -1;

}

template<>
    void ZPUino_GFX_class<uint16_t>::begin(const modeline_t *mode) {

        if (deviceBegin(0x08, 0x1B)==0 || deviceBegin(0x08,0x1A)==0) {
            unsigned sizeinfo = REG(0);
        unsigned fbsize = (sizeinfo>>16) * (sizeinfo &0xffff);
        Framebuffer<PixType>::allocate(fbsize,(sizeinfo>>16));
        memset(framebuffers,0,Framebuffer<PixType>::getSizeBytes());
        REG(0) = (unsigned)Framebuffer<PixType>::getFramebuffer();
            Adafruit_GFX_core<uint16_t>::begin(sizeinfo>>16, sizeinfo &0xffff);

        } else if (deviceBegin(0x08, 0x1D)==0) {
        unsigned fbsize = mode->hdisplay * mode->vdisplay;
            if (mode->duplicate) {
                fbsize>>=2;
            }
        Framebuffer<PixType>::allocate(fbsize,mode->hdisplay);
        REG(0) = (unsigned)getFramebuffer();

        memset(framebuffers,0,Framebuffer<PixType>::getSizeBytes());

            setupVGA(mode);
    } else if (deviceBegin(0x08, 0x21)==0) {
        unsigned fbsize = mode->hdisplay * mode->vdisplay;
        if (mode->duplicate) {
            fbsize>>=2;
        }
        Framebuffer<PixType>::allocate(fbsize,mode->hdisplay);
        REG(0) = (unsigned)getFramebuffer();

        memset(framebuffers,0,Framebuffer<PixType>::getSizeBytes());

        setupHDMI(mode);

        } else {
            Serial.println("Device not found");
        }
    }

template<>
void ZPUino_GFX_class<uint16_t>::begin(const displaymode_t mode) {

    const modeline_t *ml = NULL;

    if (deviceBegin(0x08, 0x1B)==0 || deviceBegin(0x08,0x1A)==0) {
        unsigned sizeinfo = REG(0);
        unsigned fbsize = (sizeinfo>>16) * (sizeinfo &0xffff);
        Framebuffer<PixType>::allocate(fbsize,(sizeinfo>>16));
        memset(framebuffers,0,Framebuffer<PixType>::getSizeBytes());
        REG(0) = (unsigned)Framebuffer<PixType>::getFramebuffer();
        Adafruit_GFX_core<uint16_t>::begin(sizeinfo>>16, sizeinfo &0xffff);

    } else if (deviceBegin(0x08, 0x1D)==0) {
        ml = scanModeline(mode.width(), mode.height(), COMPAT_VGA);
        if (NULL==ml) {
            Serial.println("Invalid mode for device");
            return;
        }
        unsigned fbsize = ml->hdisplay * ml->vdisplay;
        if (ml->duplicate) {
            fbsize>>=2;
        }
        Framebuffer<PixType>::allocate(fbsize,ml->hdisplay>>ml->duplicate);
        REG(0) = (unsigned)getFramebuffer();

        memset(framebuffers,0,Framebuffer<PixType>::getSizeBytes());

        setupVGA(ml);
    } else if (deviceBegin(0x08, 0x21)==0) {
        ml = scanModeline(mode.width(), mode.height(), COMPAT_HDMI);
        if (NULL==ml) {
            Serial.println("Invalid mode for device");
            return;
        }
        unsigned fbsize = ml->hdisplay * ml->vdisplay;
        if (ml->duplicate) {
            fbsize>>=2;
        }
        Framebuffer<PixType>::allocate(fbsize,ml->hdisplay>>ml->duplicate);
        REG(0) = (unsigned)getFramebuffer();

        memset(framebuffers,0,Framebuffer<PixType>::getSizeBytes());

        setupHDMI(ml);

    } else {
        Serial.println("Device not found");
    }
}




template<>
    void ZPUino_GFX_class<uint16_t>::drawFastVLine(int x, int y, int h, uint16_t color)
{
    int delta = width();
    uint16_t *p = getPosition(x,y);
    while (h--) {
        *p=color;
        p+=delta;
    }
}

template<>
void ZPUino_GFX_class<uint16_t>::drawFastHLine(int x, int y, int w, uint16_t color)
{
    uint16_t *p = getPosition(x,y);
    while (w--) {
        *p=color;
        p++;
    }
}
template<>
void ZPUino_GFX_class<uint16_t>::fillRect(int x, int y, int w, int h, uint16_t color)
{
    int delta = width() - w;
    uint16_t *p = getPosition(x,y);
    while (h--) {
        for (int z=0;z!=w;z++) {
            *p=color;
            p++;
        }
        p+=delta;
    }

}
template<>
void ZPUino_GFX_class<uint16_t>::fillScreen(uint16_t color)
{
    clearArea(0,0,width(),height(),color);
}

template<>
uint16_t ZPUino_GFX_class<uint16_t>::buildColor(unsigned r, unsigned g, unsigned b)
{
    r &= (0x1f);
    g &= (0x3f);
    b &= (0x1f);
    r<<=11;
    g<<=5;
    return r+g+b;
}

template<>
int ZPUino_GFX_class<uint8_t>::setupVGA(const modeline_t *mode)
{
    unsigned pllm,plld,pllerror;
    // First, disable display output.
    REG(2)=0;
    uint32_t temp = mode->vpol << 1 || mode->hpol;
    if (mode->duplicate)
        temp|=0x8;
    // RGB332
    temp |= 0x4;

    // Now, setup VGA
    REG(3)  = temp;
    REG(8)  = mode->hdisplay;
    REG(9)  = mode->hsyncstart;
    REG(10) = mode->hsyncend;
    REG(11) = mode->htotal;
    REG(12) = mode->vdisplay;
    REG(13) = mode->vsyncstart;
    REG(14) = mode->vsyncend;
    REG(15) = mode->vtotal;

    if (pll.begin(getBaseRegister()+PLLOFFSET)!=0) {
        return -1;
    }

    PLL_class::scanBest( pll.getclkkhz(), mode->pixelclock, &pllm, &plld, &pllerror);

    if (pllerror==PLL_ERROR) {
        Serial.println("Cannot find a suitable PLL setting for mode");
        return -1;
    }

    if (pll.set(pllm, plld)==0) {
        // Enable display output again.
        REG(2)=1;
        if (mode->duplicate) {
            Adafruit_GFX_core<PixType>::begin(mode->hdisplay>>1,mode->vdisplay>>1);
        } else {
            Adafruit_GFX_core<PixType>::begin(mode->hdisplay,mode->vdisplay);
        }
        return 0;
    }
    return -1;

}


template<>
    void ZPUino_GFX_class<uint8_t>::begin(const modeline_t *mode) {

        if (deviceBegin(0x08, 0x1B)==0 || deviceBegin(0x08,0x1A)==0) {
            unsigned sizeinfo = REG(0);
            unsigned fbsize = (sizeinfo>>16) * (sizeinfo &0xffff) * sizeof(PixType);
            framebuffers=(uint32_t*)malloc(fbsize);
            memset(framebuffers,0,fbsize);
            REG(0) = (unsigned)framebuffers;
            Adafruit_GFX_core<uint8_t>::begin(sizeinfo>>16, sizeinfo &0xffff);

        } else if (deviceBegin(0x08, 0x1D)==0) {
            unsigned fbsize = mode->hdisplay * mode->vdisplay * sizeof(uint8_t);
            if (mode->duplicate) {
                fbsize>>=2;
            }
            framebuffers=(uint32_t*)malloc(fbsize);
            REG(0) = (unsigned)framebuffers;

            memset(framebuffers,0,fbsize);

            setupVGA(mode);
        } else {
            Serial.println("Device not found");
        }
    }

template<>
    void ZPUino_GFX_class<uint8_t>::drawFastVLine(int x, int y, int h, uint8_t color)
{
    int delta = width();
    uint8_t *p = getPosition(x,y);
    while (h--) {
        *p=color;
        p+=delta;
    }
}

template<>
void ZPUino_GFX_class<uint8_t>::drawFastHLine(int x, int y, int w, uint8_t color)
{
    uint8_t *p = getPosition(x,y);
    while (w--) {
        *p=color;
        p++;
    }
}
template<>
void ZPUino_GFX_class<uint8_t>::fillRect(int x, int y, int w, int h, uint8_t color)
{
    int delta = width() - w;
    uint8_t *p = getPosition(x,y);
    while (h--) {
        for (int z=0;z!=w;z++) {
            *p=color;
            p++;
        }
        p+=delta;
    }

}
template<>
void ZPUino_GFX_class<uint8_t>::fillScreen(uint8_t color)
{
    clearArea(0,0,width(),height(),color);
}

template<>
uint8_t ZPUino_GFX_class<uint8_t>::buildColor(unsigned r, unsigned g, unsigned b)
{
    r &= (0x1f);
    g &= (0x3f);
    b &= (0x1f);
    r<<=11;
    g<<=5;
    return r+g+b;
}




#if 0
virtual void drawFastHLine(int x, int y, int w, uint16_t color)
{
    uint16_t *p = getPosition(x,y);
    uint32_t *pa = (uint32_t*)((unsigned)p &~3);
    unsigned ww;

    uint32_t color32=color<<16 | color;

    if ((unsigned)p & 0x2) {
        /* Unaligned. Align */
        w--;*p++=color;
    }
    ww=w>>1;
    while (ww--) {
        *pa=color32;
        pa++;
    }
    if (w&1) {
        p=(uint16_t*)pa;
        *++p=color;
    }
}
#endif
