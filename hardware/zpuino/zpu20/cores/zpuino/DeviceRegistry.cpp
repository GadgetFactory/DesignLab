#include "DeviceRegistry.h"
#include "register.h"
#include <zstdio.h>

namespace ZPUino {

    int DeviceRegistry::registerDevice(int slot) {
        if (slot>=MAX_SLOTS) {
#ifdef DEBUG_DEVICEREGISTRY
            printf("%s: register device on overflow slot %d\r\n",__FUNCTION__,slot);
#endif
            return -2;
        }
/*         if (m_sDeviceRegistry & (1<<slot)) {
#ifdef DEBUG_DEVICEREGISTRY
            printf("%s: cannot register device on slot %d: already registered\r\n",__FUNCTION__,slot);
#endif

            return -1;
        } */
        m_sDeviceRegistry |= (1<<slot);
#ifdef DEBUG_DEVICEREGISTRY
        printf("%s: registrer mask is now 0x%08x\r\n",__FUNCTION__,m_sDeviceRegistry);
#endif
        return 0;
    }

    uint8_t DeviceRegistry::scanDevice(unsigned vendor, unsigned product, int instance) {
        int i;
        for (i=0;i!=16;i++) {
            unsigned val = REGISTER(SYSCTLBASE,16+i);
            if (val!=0) {
#ifdef DEBUG_DEVICEREGISTRY
                printf("%s: scanning slot %d for device %04x:%04x.%d: this device is %04x:%04x\r\n",__FUNCTION__,i,(int)vendor,(int)product,(int)instance,
                      (int)((val>>8)&0xff),(int)(val&0xff)
                      );
#endif
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
#ifdef DEBUG_DEVICEREGISTRY
                    printf("%s: skipping slot %d (already registered). Instance now %d.\r\n",__FUNCTION__,i,(int)instance-1);
#endif
                    if (instance!=0xff)
                        --instance;
                    continue;
                }

                if ((instance==0xff) || (--instance)==0) {
#ifdef DEBUG_DEVICEREGISTRY
                    printf("%s: found device in slot %d (instance now %d).\r\n",__FUNCTION__,i,(int)instance);
#endif

                    return i;
                }
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
