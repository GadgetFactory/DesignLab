#include "BaseDevice.h"
#include <zstdio.h>

namespace ZPUino {
    int BaseDevice::deviceBegin(uint8_t vendor, uint8_t product) {
        uint8_t slot;
        if (m_slot==0xff) {
#ifdef DEBUG_BASEDEVICE
            printf("%s: scanning for device %04x:%04x.%d\r\n",__FUNCTION__,(int)vendor,(int)product,(int)m_instance);
#endif
            slot = DeviceRegistry::scanDevice(vendor,product,m_instance);
            if (slot==NO_DEVICE) {
                /* Uuups */
#ifdef DEBUG_BASEDEVICE
                printf("%s: device %04x:%04x.%d not found\r\n",__FUNCTION__,(int)vendor,(int)product,(int)m_instance);
#endif
                m_slot=0xff;
                return -1;
            }
        } else {
            slot=m_slot;
        }
        if (DeviceRegistry::registerDevice(slot)<0) {
#ifdef DEBUG_BASEDEVICE
            printf("%s: Unable to register device %04x:%04x.%d\r\n",__FUNCTION__,(int)vendor,(int)product,(int)m_instance);
#endif
            m_slot=0xff;
            return -1;
        }

#ifdef DEBUG_BASEDEVICE
        printf("%s: device %04x:%04x.%d registered (slot %d)\r\n",__FUNCTION__,(int)vendor,(int)product,(int)m_instance,(int)slot);
#endif
        m_slot=slot;
        m_baseaddress = (register_t)IO_SLOT(m_slot);
        return 0;
    }

    int BaseDevice::deviceBegin(const register_t base) {
        m_baseaddress = base;
        return 0;
    }

    int BaseDevice::deviceBegin(const WishboneSlot &slot) {
        if (DeviceRegistry::registerDevice(slot)<0) {
            m_slot=0xff;
            return -1;
        }
        if (DeviceRegistry::registerDevice(slot)<0) {
            m_slot=0xff;
            return -1;
        }

        m_slot=slot;
        m_baseaddress = (register_t)IO_SLOT(m_slot);
        return 0;
    }
};
