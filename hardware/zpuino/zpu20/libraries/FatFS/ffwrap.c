#include "fatfs/ff.h"
#include "zfdevice.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "disk.h"

static FATFS fs;

static void *sd_open(const char *path)
{
    ssize_t r;

    FIL *f = (FIL*)malloc(sizeof(FIL));

    r = f_open (f, path, FA_READ);            /* Open or create a file */

    if (r!=FR_OK) {
        printf("SD open error: %d\n", r);
        free(f);
        return NULL;
    }

    return f;
}

static void sd_close(void *handle)
{
    FIL *f = (FIL*)handle;
    f_close(f);
    free(f);
}

static ssize_t sd_read(void *handle,void *dest,size_t size)
{
    FIL *f = (FIL*)handle;
    ssize_t r;
    ssize_t toread = size;
    WORD bytes,chunk;
    unsigned char *b = (unsigned char*)dest;
    while (toread>0) {
        chunk = toread >= 65535 ? 65535 : toread;
        r = f_read(f, b, chunk, &bytes);
        if (r!=FR_OK) {
            printf("SD error read: %d\n",r);
            return -r;
        }
        if (bytes==0)
            break;
        toread-=bytes;
        b+=bytes;
    }
    //printf("Read ok %d bytes\r\n", size);
    return size;
}

static ssize_t sd_write(void *handle,const void *src,size_t size)
{
    return -1;
}

static ssize_t sd_fstat(void *handle,struct stat *buf)
{
    FIL *f = (FIL*)handle;
    buf->st_size = f->fsize;
    return 0;
}

static ssize_t sd_seek(void *handle,int pos, int whence)
{
    FIL *f = (FIL*)handle;

    if (whence!=SEEK_SET) {
        printf("sd_seek: unsupported seek mode %d\n", whence);
        return -1;
    }

    ssize_t r = f_lseek(f,pos);

    if (r!=FR_OK)
        return -r;

    return f->fptr;
}

static struct zfops sd_ops = {
    &sd_open,
    &sd_close,
    &sd_read,
    &sd_write,
    &sd_seek,
    &sd_fstat
};

void register_sd()
{
    ssize_t r;
    printf("Registering SD card\r\n");
    r = f_mount(0, &fs);
    if (r!=FR_OK) {
        printf("Error initialising SD/FAT: %d\r\n", r);
        return;
    }
    zfRegisterFileBackend("sd", &sd_ops);
}


/* DISK interface */

DSTATUS disk_initialize (BYTE d)
{
    return SD_disk_initialize();
}

DSTATUS disk_status (BYTE d)
{
    return SD_disk_status();
}

DRESULT disk_read (BYTE d, BYTE*buf, DWORD sect, BYTE count)
{
    return SD_disk_read(buf,sect,count);
}

DRESULT disk_ioctl (BYTE dev, BYTE op, void*buf)
{
    return SD_disk_ioctl(op,buf);
}
void  disk_timerproc (void)
{
}



