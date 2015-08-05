/*
 Posix-like utility functions
 */

#ifndef NOPOSIX

#include "zposix.h"
#include "zpuino-types.h"
#include <stdarg.h>
#include <ctype.h>
#include <sys/errno.h>
#include <time.h>

#include "Arduino.h"
#include "zfdevice.h"

struct __filedes {
    //int backend_type;
    struct zfops *ops;
    void *data;
    int mode;
};

extern "C" {

static struct __filedes __fds[MAX_FILES];
static char __cwd[128];

char *getcwd(char *buf, size_t size)
{
    return strncpy(buf,__cwd, size);
}

static char *makefullpath(char *dest, const char *pathname)
{
    char *d = dest;
    char cwd[128];

    if (pathname[0] == '/') {
        /* Full path */
        strcpy(dest,pathname);
    } else {
        getcwd(cwd, sizeof(cwd));
        size_t len = strlen(cwd);
        strcpy(d,cwd);
        d+=len;
        // CWD never ends with '/', except if we are on root.
        if (len!=1) {
            *d++='/';
            *d='\0';
        }
        strcat(d,pathname);
    }
    return dest;
}


int chdir(const char *path)
{
    if (path[0]=='/') {
        strcpy(__cwd, path);
    } else {
        if (strlen(__cwd)==1) {
            /* Root */
            strcat(__cwd, path);
        } else {
            strcat(__cwd,"/");
            strcat(__cwd, path);
        }
    }
    // Strip last "/" if present.
    size_t len = strlen(__cwd);
    while (len>0 && __cwd[len]=='/') {
        __cwd[len--]='\0';
    }
    return 0;
}

void debugprint(const char *c)
{
    volatile unsigned int *ptr = (volatile unsigned int*)0x90000000;
    while (*c) {
        while ((*(ptr+1)&0x2)!=0);
        *ptr = *c;
        c++;
    };
}

#define BACKEND_PRINT 1

/* Raw file I/O */

int open(const char *pathname, int flags,...)
{
    char rdevice[16];
    char path[128];
    char *pptr;
    int newfd=-1;
    int i;

    for (i=0;i!=MAX_FILES;i++) {
        if (__fds[i].ops == NULL) {
            newfd=i;
            break;
        }
    }

    if (newfd==-1)
        return newfd;

    __fds[newfd].mode = flags;

    if ((pathname==NULL) || (pathname[0]=='\0'))
        return -1;

    makefullpath(path, pathname);

    if (path[0]!='/') {
        return -1;
    }

    pptr=&path[1];

    const char *delim = strchr(pptr,'/');

    if (NULL==delim) {
        return -1;
    } else {
        if (!*delim) {
            return -1;
        }

        if ((delim-pptr) > 15) {
        return -1; /* Too large */
        }

        strncpy(rdevice, pptr, delim-pptr);
        rdevice[delim-pptr] = '\0';

        delim++;
    }


    /* Look it up */
    struct zfops *ops = zfFindBackend(rdevice);

    if (ops==NULL) {
        return -1;
    }
    
    void *handle = ops->open(delim);

    if (NULL==handle) {
        return -1;
    }

    __fds[newfd].ops = ops;
    __fds[newfd].data = handle;

    return newfd;
}

int close(int fd)
{
    int ret = 0;
    if (__fds[fd].ops) {
        if (__fds[fd].ops->close) {
            __fds[fd].ops->close(__fds[fd].data);
        }
        __fds[fd].ops = NULL;
    }
    return ret;
}

ssize_t read(int fd, void *buf, size_t count)
{
    int ret = -1;
    if (__fds[fd].ops) {
        if (__fds[fd].ops->read) {
            ret = __fds[fd].ops->read(__fds[fd].data,buf,count);
        }
    }
    return ret;

}

int fstat(int fd, struct stat *buf)
{
    int ret = -1;
    if (__fds[fd].ops) {
        if (__fds[fd].ops->fstat) {
            ret = __fds[fd].ops->fstat(__fds[fd].data,buf);
        }
    }
    return ret;
}

ssize_t write(int fd, const void *buf, size_t count)
{
    int ret = -1;
    if (__fds[fd].ops) {
        if (__fds[fd].ops->write) {
            ret = __fds[fd].ops->write(__fds[fd].data,buf,count);
        }
    }
    return ret;
}

extern "C" void abort()
{
    while(1);
}

char *strerror(int err)
{
    return "Unknown";
}


off_t lseek(int fd, off_t offset, int whence)
{
    int ret = -1;
    if (__fds[fd].ops) {
        if (__fds[fd].ops->seek) {
            ret = __fds[fd].ops->seek(__fds[fd].data,offset,whence);
        }
    }
    return ret;
}

struct tm dummytm;

struct tm *gmtime(const time_t *timep)
{
    return &dummytm;
}

void __attribute__((constructor)) __posix_init()
{
    static int initialized=0;
    int i;

    if (initialized)
        return;
    for (i=0;i!=MAX_FILES;i++) {
        __fds[i].ops=NULL;
    }
    __cwd[0]='/';
    __cwd[1]='\0';
    initialized=1;
}

int access(const char *pathname, int mode)
{
    return 0;
}
int isatty(int fd)
{
    return 0;
}


}

#endif
