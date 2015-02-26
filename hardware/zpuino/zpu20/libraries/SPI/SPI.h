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
#define SPI_CLOCK_DIV2 BIT(SPICP0)
#define SPI_CLOCK_DIV4 BIT(SPICP1)
#define SPI_CLOCK_DIV8 (BIT(SPICP1)|BIT(SPICP0))
#define SPI_CLOCK_DIV16 BIT(SPICP2)
#define SPI_CLOCK_DIV64 (BIT(SPICP2)|BIT(SPICP0))
#define SPI_CLOCK_DIV256 (BIT(SPICP2)|BIT(SPICP1))
#define SPI_CLOCK_DIV1024 (BIT(SPICP2)|BIT(SPICP1)|BIT(SPICP0))

/* Note - these modes are not 100% accurate yet */

#define SPI_MODE0 0
#define SPI_MODE1 BIT(SPISRE)
#define SPI_MODE2 BIT(SPICPOL)
#define SPI_MODE3 (BIT(SPICPOL)|BIT(SPISRE))

#define SPI_CLOCK_MASK (BIT(SPICP0)|BIT(SPICP1)|BIT(SPICP2))
#define SPI_MODE_MASK (BIT(SPICPOL)|BIT(SPISRE))

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
  SPIClass(const WishboneSlot &slot);
  byte transfer(unsigned _data);
  uint16_t transfer16(unsigned _data);
  uint32_t transfer24(unsigned _data);
  uint32_t transfer32(unsigned _data);
  uint32_t read();
  void send(unsigned _data);
  void send16(unsigned _data);
  void send24(unsigned _data);
  void send32(unsigned _data);

  void begin(MOSI mosi, MISO miso, SCK sck);
  void begin();
  void begin(int wishboneSlot);
  void begin(const WishboneSlot &slot);
  void end();

  void setBitOrder(int);
  void setDataMode(int);
  void setClockDivider(int);
private:
  int wishboneSlot;  
};

extern SPIClass SPI;

#endif
