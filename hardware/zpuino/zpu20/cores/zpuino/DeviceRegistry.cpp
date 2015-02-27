#include "DeviceRegistry.h"
#include "register.h"

namespace ZPUino {

    int DeviceRegistry::registerDevice(int slot) {
        if (slot>=MAX_SLOTS)
            return -2;
        if (m_sDeviceRegistry & (1<<slot))
            return -1;
        m_sDeviceRegistry |= (1<<slot);
        return 0;
    }

    uint8_t DeviceRegistry::scanDevice(unsigned vendor, unsigned product, int instance) {
        int i;
        for (i=0;i!=16;i++) {
            unsigned val = REGISTER(SYSCTLBASE,16+i);
            if (val!=0) {
                if (vendor!=VENDOR_ANY) {
                    if (vendor != ((val>>8)&0xff))
                        continue; /* No match */
                }
                if (product!=PRODUCT_ANY) {
                    if (product != (val&0xff))
                        continue; /* No match */
                }
                if (isRegistered(i))
                {
                    --instance;
                    continue;
                }

                if ((instance==0xff) || (--instance)==0)
                    return i;
            }
        }
        return NO_DEVICE;
    }

    int DeviceRegistry::getPPSInputPin(int masterslot, int offset)
    {
        return getPPSPin(masterslot,offset,16);
    }

    int DeviceRegistry::getPPSOutputPin(int masterslot, int offset)
    {
        return getPPSPin(masterslot,offset,0);
    }

    int DeviceRegistry::getPPSPin(int masterslot, int offset, int shift)
    {
        unsigned count = REGISTER(SYSCTLBASE, 32+shift);
        unsigned start = (unsigned)-1;
        register_t startreg = &REGISTER(SYSCTLBASE, 64);
        
        while(count--) {
            start++;
            unsigned val = *startreg++;
            unsigned char dev = (val>>shift)&0xff;
            if (dev!=masterslot) {
                continue;
            } else {
                //int pin = (val>>(8+shift))&0xff;
                if (offset==0)
                    return start;
                offset--;
            }
        }
        return -1;
    }

    uint32_t DeviceRegistry::m_sDeviceRegistry = 0;
};
