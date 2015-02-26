#ifndef __DISK_H__
#define __DISK_H__

#define _USE_IOCTL 1

#include "diskio.h"


DRESULT SD_disk_ioctl (
	BYTE cmd,		/* Control code */
	void *buff		/* Buffer to send/receive control data */
);
DRESULT SD_disk_read (
	BYTE *buff,		/* Data buffer to store read data */
	DWORD sector,	/* Sector address (LBA) */
	UINT count		/* Number of sectors to read (1..128) */
                     );
DSTATUS SD_disk_status (void);
DSTATUS SD_disk_initialize (void);



#endif