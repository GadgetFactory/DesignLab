//#include "AVR_Wishbone_Bridge.h"
//#include "SPI.h"

struct vendor_type {
    uint8_t vendor;
    const char *name;
};

const struct vendor_type vendors[] = {
    { 0x08, "ZPUino" },
    { 0x02, "VGAArcade" },
    { 0x03, "ZPUino Contrib" },
    { 0x04, "OpenCores" },
    { 0x0, NULL }
};

struct product_type {
    uint8_t vendor;
    uint8_t product;
    const char *name;
};

const struct product_type products[] = {
    { 0x08, 0x01, "System Controller" },
    { 0x08, 0x02, "Bootloader Code" },
    { 0x08, 0x03, "On-board SPI flash" },
    { 0x08, 0x10, "SPI interface" },
    { 0x08, 0x11, "UART" },
    { 0x08, 0x12, "GPIO Controller" },
    { 0x08, 0x13, "Dual Timer Interface with PWM" },
    { 0x08, 0x14, "16-Bit Dual SigmaDelta" },
    { 0x08, 0x15, "Hardware CRC16 engine" },
    { 0x08, 0x16, "Seven Segment Display Driver" },
    { 0x08, 0x18, "HQVGA (240x160) 8-bit Graphics Adaptor" },
    { 0x08, 0x19, "8-bit single-port Character RAM" },
    { 0x08, 0x1A, "VGA (640x480) 15-bit Graphics Adaptor" },
    { 0x08, 0x1B, "VGA Text-mode (640x480) 80x30 3-bit Adaptor" },
    { 0x08, 0x1C, "ZX Spectrum Graphics Adaptor" },
    { 0x08, 0x1D, "VGA Generic Interface (8/16-bit)" },
    { 0x08, 0x1E, "PLL Clock Generator" },
    { 0x08, 0x20, "RGB LED Controller" },
    { 0x02, 0x01, "YM2149 Sound Chip" },
    { 0x02, 0x02, "POKEY Sound Chip" },
    { 0x03, 0x01, "SID6581 Sound Chip" },
    { 0x04, 0x01, "I2C Master Controller" },
    { 0x04, 0x02, "CORDIC" },
    { 0x0, 0x0, NULL }
};

const struct vendor_type *getVendor(uint8_t vendor)
{
    int i;
    for (i=0;vendors[i].name;i++) {
        if (vendor==vendors[i].vendor)
            return &vendors[i];
    }
    return NULL;
}

const struct product_type *getVendorProduct(uint8_t vendor,uint8_t product)
{
    int i;
    for (i=0;products[i].name;i++) {
        if (vendor==products[i].vendor && product==products[i].product) {
            return &products[i];
        }
    }
    return NULL;
}

void showSystemInfo()
{
    unsigned int basereg = 16;
    const struct product_type * p[16];
    const struct vendor_type *v[16];
    int sppout, sppin;

    int i;
    for (i=0;i<16;i++) {
        Serial.print("Slot ");
        Serial.print(i);
        Serial.print(": ");
        unsigned val = REGISTER(SYSCTLBASE,basereg+i);
        if (val==0) {
            p[i]=NULL;
            v[i]=NULL;
            Serial.println("No device attached");
        } else {
            v[i] = getVendor(val>>8);
            Serial.print(v[i]->name ? v[i]->name:"Unknown vendor");
            Serial.print(" ");
            p[i] = getVendorProduct(val>>8,val&0xff);
            Serial.println(p[i] ? p[i]->name : "Unknown product");
        }
    }
    sppout = REGISTER(SYSCTLBASE, 32);
    sppin =  REGISTER(SYSCTLBASE, 48);

    Serial.print("PPS outputs: ");
    Serial.println( sppout );

    for (i=0;i<32;i++) {
        unsigned val = REGISTER(SYSCTLBASE, 64+i);
        if (i<sppout) {
            Serial.print("  PPS");
            Serial.print(i);
            Serial.print(" ");
            unsigned char dev = val&0xff;
            if (dev==0xff) {
                /* Not connected */
                Serial.println("is not used.");
            } else {
                Serial.print("maps pin ");
                Serial.print((val>>8)&0xff);
                Serial.print(" of '");

                if (dev<16) {
                    if (p[dev]) {
                        Serial.print(p[dev]->name);
                    }
                    Serial.print("' in slot ");
                    Serial.println(dev);
                }
            }
        }
    }

    Serial.print("SPP inputs: ");
    Serial.println( sppin );

    for (i=0;i<32;i++) {
        unsigned val = REGISTER(SYSCTLBASE, 64+i);
        if (i<sppin) {
            Serial.print("  PPS");
            Serial.print(i);
            Serial.print(" ");
            unsigned char dev = (val>>16)&0xff;
            if (dev==0xff) {
                /* Not connected */
                Serial.println("is not used.");
            } else {
                Serial.print("maps pin ");
                Serial.print((val>>24)&0xff);
                Serial.print(" of '");

                if (dev<16) {
                    if (p[dev]) {
                        Serial.print(p[dev]->name);
                    }
                    Serial.print("' in slot ");
                    Serial.println(dev);
                }
            }
        }
    }

}

void setup()
{
	Serial.begin(115200);
        //SPI.begin();
        delay(3000);
}

void loop()
{
    int i;
#if 1
    Serial.println("Press ENTER to show system info");

    while (!Serial.available());
    Serial.read();
#endif
    showSystemInfo();
}
