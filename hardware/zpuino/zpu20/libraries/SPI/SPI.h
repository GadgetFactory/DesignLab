/*
 * Copyright (c) 2010 by Cristian Maglie <c.maglie@bug.st>
 * SPI Master library for arduino.
 *
 * This file is free software; you can redistribute it and/or modify
 * it under the terms of either the GNU General Public License version 2
 * or the GNU Lesser General Public License version 2.1, both as
 * published by the Free Software Foundation.
 */

#ifndef _SPI_H_INCLUDED
#define _SPI_H_INCLUDED

#include <Arduino.h>
#include <BaseDevice.h>

#include <zpuino-types.h>
#include <zpuino.h>

using namespace ZPUino;

#define SPI_CLOCK_DIV0 0
#define SPI_CLOCK_DIV2 SPICP0
#define SPI_CLOCK_DIV4 SPICP1
#define SPI_CLOCK_DIV8 (SPICP1|SPICP0)
#define SPI_CLOCK_DIV16 SPICP2
#define SPI_CLOCK_DIV64 (SPICP2|SPICP0)
#define SPI_CLOCK_DIV256 (SPICP2|SPICP1)
#define SPI_CLOCK_DIV1024 (SPICP2|SPICP1|SPICP0)

/* Note - these modes are not 100% accurate yet */

#define SPI_MODE0 0
#define SPI_MODE1 SPISRE
#define SPI_MODE2 SPICPOL
#define SPI_MODE3 (SPICPOL|SPISRE)

#define SPI_CLOCK_MASK (SPICP0|SPICP1|SPICP2)
#define SPI_MODE_MASK (SPICPOL|SPISRE)

enum SPITransferMode {
	SPI_CONTINUE,
	SPI_LAST
};

#define INTVAL(x) \
struct x {                             \
    explicit x(int i):v(i){};          \
    inline operator int () { return v; } \
private:                               \
    x &operator=(int v);               \
    int v;                             \
}

INTVAL(CS);
INTVAL(MISO);
INTVAL(MOSI);
INTVAL(SCK);

class SPIClass: public BaseDevice {
public:
  SPIClass(int index=1);
  byte transfer(unsigned _data);
  uint16_t transfer16(unsigned _data);
  uint32_t transfer32(unsigned _data);

  void begin(MOSI mosi, MISO miso, SCK sck);
  void begin();
  void end();

  void setBitOrder(int);
  void setDataMode(int);
  void setClockDivider(int);
};

extern SPIClass SPI;

#endif
