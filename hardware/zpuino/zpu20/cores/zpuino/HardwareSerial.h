#ifndef __HardwareSerial_h__
#define __HardwareSerial_h__

#include "zstdio.h"

#include <zpuino.h>
#include <zpuino-types.h>
#include "Stream.h"
#include "Print.h"
#include "BaseDevice.h"
#include "zfdevice.h"

#define VENDOR_ZPUINO       0x08
#define PRODUCT_ZPUINO_UART 0x11

namespace ZPUino {
};

#ifdef HAVE_ZFDEVICE
int serial_register_device(const char *name, void*data);
#endif

#define HWSERIAL_INTVAL(x) \
struct x {                             \
    explicit x(int i):v(i){};          \
    inline operator int () { return v; } \
private:                               \
    x &operator=(int v);               \
    int v;                             \
}

HWSERIAL_INTVAL(TX);
HWSERIAL_INTVAL(RX);

class HardwareSerial: public ZPUino::BaseDevice, public Stream
{
private:
public:
	HardwareSerial(uint8_t instance=0xff): BaseDevice(instance) {}
        HardwareSerial(const ZPUino::WishboneSlot &slot): BaseDevice(slot) {}

	__attribute__((always_inline)) inline void begin(const unsigned int baudrate) {
		if (deviceBegin(VENDOR_ZPUINO, PRODUCT_ZPUINO_UART)==0) {
			if (__builtin_constant_p(baudrate)) {
				REG(1) = BAUDRATEGEN(baudrate) | BIT(UARTEN);
			} else {
				begin_slow(baudrate);
                        }
#ifdef HAVE_ZFDEVICE
                        if (getInstance()!=0xff) {
                            /* Register it */
                            char name[16];
                            sprintf(name,"serial%d",getInstance());
                            lastCharCR=false;
                            serial_register_device(name,this);
                        }
#endif
		}
	}

        __attribute__((always_inline)) inline void begin(const unsigned int baudrate, TX tx, RX rx) {
		if (deviceBegin(VENDOR_ZPUINO, PRODUCT_ZPUINO_UART)==0) {
			if (__builtin_constant_p(baudrate)) {
				REG(1) = BAUDRATEGEN(baudrate) | BIT(UARTEN);
			} else {
				begin_slow(baudrate);
			}
                }
                setPins(tx,rx);
	}
	void begin_slow(const unsigned int baudrate);

	int available(void) {
		return (REG(1) & 1);
	}
        void setPins(TX tx, RX rx);

	virtual int read(void) {
		return REG(0);
	}

	virtual void flush(void);

	size_t write(uint8_t c);
#ifdef HAVE_ZFDEVICE
        size_t writeAndTranslate(const uint8_t *str, int size);
#endif
	virtual int peek() { return -1; }

        virtual void setBaudRate(unsigned baudrate)
        {
            if (__builtin_constant_p(baudrate)) {
                REG(1) = BAUDRATEGEN(baudrate) | BIT(UARTEN);
            } else {
                begin_slow(baudrate);
            }
        }

	using Print::write; // pull in write(str) and write(buf, size) from Print
private:
#ifdef HAVE_ZFDEVICE
    bool lastCharCR;
#endif
	unsigned int ioslot;
};

extern void serialEventRun(void) __attribute__((weak));

extern HardwareSerial Serial; /* 1st slot */
extern HardwareSerial Serial1; /* 2nd slot */

#endif
