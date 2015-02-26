#include "FatFS.h"

extern "C" void register_sd();

FatFS_class::FatFS_class()
{
}

SPIClass *FatFS_class::s_spi=0;
int FatFS_class::s_csline=-1;
void FatFS_class::begin(SPIClass &spi, int csline)
{
    s_spi=&spi;
    s_csline=csline;
    digitalWrite(csline,HIGH);
    pinMode(csline,OUTPUT);
    spi.setDataMode(SPI_MODE3);
    spi.setClockDivider(SPI_CLOCK_DIV4);
    register_sd();
}

extern "C" unsigned c_millis()
{
    return millis();
}

extern "C" void usleep(unsigned us)
{
    delay(us/1000);
}

extern "C" void spi_select(int val)
{
    if (FatFS_class::s_csline>=0)
        digitalWrite(FatFS_class::s_csline,val);
}

extern "C" unsigned int spi_transfer8(unsigned int val)
{
    if (FatFS_class::s_spi!=0)
        return FatFS_class::s_spi->transfer(val);
    return 0;
}


FatFS_class FatFS;
