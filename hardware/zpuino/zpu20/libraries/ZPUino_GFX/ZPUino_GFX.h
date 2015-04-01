#include <Adafruit_GFX.h>
#include <PLL.h>
#include <Arduino.h>

using namespace ZPUino;

typedef struct  {
    uint8_t pllm;
    uint8_t plld;
    uint16_t hdisplay;
    uint16_t hsyncstart;
    uint16_t hsyncend;
    uint16_t htotal;
    uint16_t vdisplay;
    uint16_t vsyncstart;
    uint16_t vsyncend;
    uint16_t vtotal;
    uint8_t hpol:1;
    uint8_t vpol:1;
    uint8_t duplicate:1;
} modeline_t;

extern const modeline_t modeline_320x240_60;
extern const modeline_t modeline_400x300_60;
extern const modeline_t modeline_512x384_60;
extern const modeline_t modeline_640x384_60;
extern const modeline_t modeline_640x480_60;
extern const modeline_t modeline_640x512_60;
extern const modeline_t modeline_800x600_60;
extern const modeline_t modeline_1024x768_60;
extern const modeline_t modeline_1280x768_60;
extern const modeline_t modeline_1280x1024_60;



class Font;

template<typename PixelType>
    class ZPUino_GFX_class:
    public BaseDevice,
    public Adafruit_GFX_core<PixelType>
{
public:
    ZPUino_GFX_class(): Adafruit_GFX_core<PixelType>() {
    }

    typedef PixelType PixType;

    void begin(const modeline_t *mode = &modeline_640x480_60);

    PixelType *getFramebuffer() {
        return (PixelType*)framebuffers;
    }

    PixelType *getDisplayFramebuffer() {
        return (PixelType*)framebuffers;
    }

    unsigned getFramebufferSizeBytes() const {
        return Adafruit_GFX_core<PixelType>::width()*Adafruit_GFX_core<PixelType>::height()*sizeof(PixelType);
    }

    PixelType *getPosition(int x, int y) {
        return &getFramebuffer()[x + y*Adafruit_GFX_core<PixelType>::width()];
    }

    void setPixel(unsigned x, unsigned y, PixelType value) {
        if (x>Adafruit_GFX_core<PixelType>::width()-1)
            x=Adafruit_GFX_core<PixelType>::width()-1;
        if (y>Adafruit_GFX_core<PixelType>::height()-1)
            y=Adafruit_GFX_core<PixelType>::height()-1;
        getFramebuffer()[x + y*Adafruit_GFX_core<PixelType>::width()] = value;
    }

    PixelType buildColor(unsigned r, unsigned g, unsigned b);


    void putChar(int x, int y, int c, Font &font);
#if 0
    {
        c&=0xff;
        x*=font.getWidth();
        y*=font.getHeight();
        unsigned char *source = font.getChar(c);
        int i,z;
        for (i=0;i<font.getHeight();i++) {
            unsigned char v = *source++;
            for (z=0;z<font.getWidth();z++) {
                int set = !!(v &0x80);
                if (set) {
                    setPixel(x+z,y+i,0xffff);
                }
                v<<=1;
            }
        }
    }

    void putString(int x, int y, const char *c, Font &font)
    {
        while (*c) {
            putChar(x,y,*c,font);
            c++;
            x++;
            if (x> width()/font.getWidth()) {
                y++,x=0;
            }
        }
    }
#endif
    void syncVBlank()
    {
        while (!(REG(0)&1));
        /* Now, wait for vblank */
        while (REG(0)&1);
    }

    void clearArea(int sx, int sy, int w, int h, uint16_t color)
    {
        unsigned delta = Adafruit_GFX_core<PixelType>::width()-w;
        PixelType *dest = getFramebuffer();
        dest+=sx+(sy*Adafruit_GFX_core<PixelType>::width());
        while (h--) {
            int z = w;
            while (z--) {
                *dest++=color;
            }
            /* Move dest forward, to next line */
            dest+=delta;
            sy++;
        }
    }

    virtual void drawPixel(int x, int y, PixelType color) {
        setPixel(x,y,color);
    }

    virtual void drawFastVLine(int x, int y, int h, PixelType color);
    virtual void drawFastHLine(int x, int y, int w, PixelType color);
    virtual void fillRect(int x, int y, int w, int h, PixelType color);
    virtual void fillScreen(PixelType color);

#define PLLOFFSET 128

    int setupVGA(const modeline_t *mode);
protected:
    uint32_t *framebuffers;
    PLL_class pll;
};

typedef ZPUino_GFX_class<uint16_t> ZPUino_GFX;
typedef ZPUino_GFX_class<uint8_t> ZPUino_GFX_small;
