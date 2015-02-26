#ifndef __BASEDEVICE_H__
#define __BASEDEVICE_H__

#include <config.h>
#include "register.h"
#include "DeviceRegistry.h"

namespace ZPUino {

    class REGBIT
    {
    public:
        REGBIT(register_t&r, int bit): _r(r),_b(bit) {
        }
        REGBIT &operator=(bool value) {
            if (value)
                *_r = *_r | (1<<_b);
            else
                *_r = *_r &  ~(1<<_b);
            return *this;
        }
    private:
        register_t _r;
        int _b;
    };

    class REGW {
    public:
        REGW(register_t reg): _r(reg) {};
        inline operator uint32_t const ()
        {
            return*_r;
        }
        void operator=(uint32_t value) { *_r=value; }
        //uint32_t operator&(uint32_t val) const { return *_r & val; }
        inline void setBit(int bit) { *_r = *_r | BIT(bit); }
        inline void clearBit(int bit) { *_r = *_r & ~(BIT(bit)); }
        inline REGBIT bit(int bit) { return REGBIT(_r,bit); }
    private:
        register_t _r;
    };

    class REGAccess {
    public:
        inline void begin(register_t r) { m_baseaddress=r;}
        inline REGW REG(uint32_t offset=0) {
            return REGW(m_baseaddress+offset);
        }
        inline const REGW REG(uint32_t offset=0) const {
            return REGW(m_baseaddress+offset);
        }
        register_t getBaseRegister() { return m_baseaddress; }

    protected:
        register_t m_baseaddress;
    };

    struct WishboneSlot {
        explicit WishboneSlot(uint8_t number): m_slot(number) {}
        operator uint8_t () const { return m_slot; }
    private:
        int m_slot;
    };

    class BaseDevice: public REGAccess {
    public:
        BaseDevice(uint8_t instance=0xff): m_slot(0xff), m_instance(instance) {}
        BaseDevice(const WishboneSlot &slot): m_slot(slot), m_instance(0x0) {}
        int deviceBegin(uint8_t vendor, uint8_t product);
        int deviceBegin(const WishboneSlot &slot);
        int deviceBegin(const register_t base);
        int isError() { return m_slot==0xff; }
        inline uint8_t getSlot() const { return m_slot; }
        inline uint8_t getInstance() const { return m_instance; }
    protected:
    private:
        uint8_t m_slot;
        uint8_t m_instance;
    };
};

#endif
