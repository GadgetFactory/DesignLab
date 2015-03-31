#include <ZPUino_GFX.h>

const modeline_t modeline_640x480_60 =   {21,35,640,656,752,800,480,490,492,525,1,1,0};
const modeline_t modeline_320x240_60 =   {21,35,640,656,752,800,480,490,492,525,1,1,1};
const modeline_t modeline_800x600_60 =   {20,21,800,840,968,1056,600,601,605,628,0,0,0};
const modeline_t modeline_400x300_60 =   {20,21,800,840,968,1056,600,601,605,628,0,0,1};
const modeline_t modeline_1024x768_60 =  {17,11,1024,1048,1184,1344,768,771,777,806,1,1,0};
const modeline_t modeline_512x384_60 =  {17,11,1024,1048,1184,1344,768,771,777,806,1,1,1};
const modeline_t modeline_1280x768_60 =  {13,8,1280,1328,1360,1440,768,771,778,790,0,0,0};
const modeline_t modeline_640x384_60 =  {13,8,1280,1328,1360,1440,768,771,778,790,0,0,1};
const modeline_t modeline_1280x1024_60 = {18,7,1280,1328,1440,1688,1024,1025,1028,1066,0,0,0};
const modeline_t modeline_640x512_60 = {18,7,1280,1328,1440,1688,1024,1025,1028,1066,0,0,1};

template<>
int ZPUino_GFX_class<uint16_t>::setupVGA(const modeline_t *mode)
{
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
    if (pll.set(mode->pllm, mode->plld)==0) {
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
            unsigned fbsize = (sizeinfo>>16) * (sizeinfo &0xffff) * sizeof(uint16_t);
            framebuffers=(uint32_t*)malloc(fbsize);
            memset(framebuffers,0,fbsize);
            REG(0) = (unsigned)framebuffers;
            Adafruit_GFX_core<uint16_t>::begin(sizeinfo>>16, sizeinfo &0xffff);

        } else if (deviceBegin(0x08, 0x1D)==0) {
            unsigned fbsize = mode->hdisplay * mode->vdisplay * sizeof(uint16_t);
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
    if (pll.set(mode->pllm, mode->plld)==0) {
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
