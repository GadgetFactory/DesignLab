#ifndef __ZPUINO_FATFS_H__
#define __ZPUINO_FATFS_H__

#include "SPI.h"
#include "Arduino.h"

using namespace ZPUino;

class FatFS_class
{
public:
    FatFS_class();

    void begin(SPIClass &spi, int cs);

    static SPIClass *s_spi;
    static int s_csline;
};

extern FatFS_class FatFS;

#endif
