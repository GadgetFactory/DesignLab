#ifndef NOPOSIX

#include "zstdio.h"
#include "zposix.h"
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

static struct __zFILE __files[MAX_FILES];

static char _snprintfbuf[8192];

FILE*stdout=&__files[1];
FILE*stderr=&__files[2];

extern void __stdio_init();

static inline size_t __utoa(unsigned long i, char**dest, int base, size_t size, int pad, int fill, int upper);

#define UNIMPLEMENTED(x) fprintf(stderr,"ERROR: function %s not implemented\r\n", __PRETTY_FUNCTION__);

int printf(const char *format, ...)
{
    int r;
    va_list ap;
    va_start(ap,format);
    r = vsnprintf(_snprintfbuf, sizeof(_snprintfbuf), format, ap);
    fwrite(_snprintfbuf, r, 1, stdout);
    va_end(ap);
    return r;
}

int fprintf(FILE *stream, const char *format, ...)
{
    int r;
    va_list ap;
    va_start(ap,format);
    r = vsnprintf(_snprintfbuf, sizeof(_snprintfbuf), format, ap);
    fwrite(_snprintfbuf, r, 1, stream);
    va_end(ap);
    return r;
}

int sprintf(char *str, const char *format, ...) {
    va_list ap;
    va_start(ap,format);
    int r = vsnprintf(str, 0x7fffffff, format, ap);
    va_end(ap);
    return r;
}

static inline size_t __utoa(unsigned long i, char**dest, int base, size_t size, int pad, int fill, int upper)
{
    char temp[65];
    char *str = &temp[sizeof(temp)];
    int s=0;
    
    if (size<1)
        return size;

    *str='\0';

    do {
        unsigned long m = i;
        i /= base;
        char c = m - base * i;
        *--str = c < 10 ? c + '0' : c + upper - 10;
        s++;
    } while(i);

    /* Copy back */
    while (s<pad) {
        *--str=fill; s++;
    }

    s=0;

    while (*str && (size!=0)) {
        **dest=*str++;
        size--,s++;
        (*dest)++;
    }
    return s;
}

int vsnprintf(char *str, size_t size, const char *format, va_list ap)
{
    const char *start = str;
    char sizespec[4];
    int spptr=0;
    int isformat = 0;
    int upper;
    int base;
    int pad;
    int fill=0;

    size--;

    while (*format && size) {

        if (isformat) {
            base=10;
            upper='A';
            switch (*format) {
            case 'D':
            case 'd':
                do {
                    int n = va_arg(ap, int);
                    if (n<0) {
                        n=-n;
                        *str++='-', size--;
                    }
                    if (spptr) {
                        sizespec[spptr]='\0';
                        spptr=0;
                        pad=atoi(sizespec);
                    } else {
                        pad=0;
                    }
                    size -= __utoa(n,&str,base,size,pad,fill,upper);
                } while (0);
                format++ , isformat=0;
                continue;
            case 'x':
                upper='a';
            case 'X':
                base=16;
            case 'U':
            case 'u':
                do {
                    unsigned n = va_arg(ap, unsigned);
                    if (spptr) {
                        sizespec[spptr]='\0';
                        spptr=0;
                        pad=atoi(sizespec);
                    } else {
                        pad=0;
                    }
                    size -= __utoa(n,&str,base,size,pad,fill,upper);
                } while (0);
                format++ , isformat=0;
                continue;
            case 's':
                do {
                    const char *st = va_arg(ap,const char*);
                    /* To-do: padding */
                    while (size-- && *st) {
                        *str++=*st++;
                    }
                } while (0);
                break;
            case 'l':
                format++;
                continue;
            default:
                if (isdigit(*format)) {
                    if ((*format)!='0' || spptr) {
                        /* Size specifier */
                        sizespec[spptr++]=*format;
                    }
                    if (spptr==0 && *format=='0') {
                        /* Padding char */
                        fill=*format;
                    }
                }
                else {
                    /* Unknown format, ignore */
                    format++, isformat=0;
                    continue;
                }
                format++;
                continue;
            }

            format++,isformat=0;
            continue;
        }
        if (*format=='%') {
            isformat=1, format++;
            continue;
        }

        fill=' ';

        /* Normal char */
        if (!size)
            break;
        size--,*str++=*format++;
    }

    *str='\0';

    return (str-start);
}

int snprintf(char *dest, size_t size, const char *format, ...)
{
    int r;
    va_list ap;
    va_start(ap,format);
    r = vsnprintf(dest, size, format, ap);
    va_end(ap);
    return r;
}

static FILE *__find_free_file()
{
    int i;
    for (i=0;i<MAX_FILES;i++) {
        if (__files[i].fd<0) {
            return &__files[i];
        }
    }
    return NULL;
}


FILE *fopen(const char *path, const char *mode)
{
    FILE *r = __find_free_file();
    if (NULL==r)
        return r;

    int fd = open(path,O_RDONLY);
    //fprintf(stderr,"Attempting to open %s\r\n",path);
    if (fd<0)
        return NULL;
    //fprintf(stderr,"Opened %s, fd %d\r\n",path, fd);
    
    r->fd = fd;
    return r;
}

FILE *fdopen(int fd, const char *mode)
{
    FILE *r = __find_free_file();
    if (NULL==r)
        return r;
    r->fd = fd;
    return r;
}

int fseek(FILE *stream, long offset, int whence)
{
    UNIMPLEMENTED();
    return -1;
}
long ftell(FILE *stream)
{
    UNIMPLEMENTED();
    return -1;
}
void rewind(FILE *stream)
{
    UNIMPLEMENTED();
}
int fgetpos(FILE *stream, fpos_t *pos)
{
    UNIMPLEMENTED();
    return -1;
}
int fsetpos(FILE *stream, fpos_t *pos)
{
    UNIMPLEMENTED();
    return -1;
}


size_t fwrite(const void *ptr, size_t size, size_t nmemb,
              FILE *stream) {
    size_t n=0;

    unsigned char *ptrc=(unsigned char*)ptr;
    if (!stream || stream->fd<0)
        return -1;

    while (nmemb--) {
        n+=write( stream->fd, ptrc, size);
        ptrc+=size;
    };
    return n;
}

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)
{
    size_t n=0,bytesread;
    unsigned char *ptrc=(unsigned char*)ptr;
    if (!stream || stream->fd<0)
        return -1;
    /* Speed things if size==1 */
    if (size==1) {
        n = read(stream->fd,ptrc,nmemb);
        if (n<0)
            n=0;
    } else {
        while (nmemb--) {
            bytesread=read( stream->fd, ptrc, size);
            if (bytesread!=size)
                break;
            n++;
            ptrc+=size;
        }
    }
#if 0
    fprintf(stderr,"Read fd %d, size %d, nmemb %d, %d\r\n",stream->fd,size,nmemb,n);
    {
        int i;
        for (i=0;i<n;i++) {
            fprintf(stderr,"%02x ", ((unsigned char*)ptr)[i]);
        }
        fprintf(stderr,"\r\n");
    }
#endif
    return n;
}


extern void __posix_init();

void stdio_register_console(const char *device)
{
    if (__files[0].fd >= 0 || __files[1].fd >= 0)
        return;

    /* Open device for stdin/out/err */

    __files[0].fd = open(device,O_RDONLY);
    __files[1].fd = __files[2].fd = open(device,O_RDWR);
}



void fclose(FILE*p)
{
    if (p->fd==-1)
        return;
    close(p->fd);
    p->fd=-1;
}

int fflush(FILE*p)
{
    return 0;
}

int fputc(int c, FILE *stream)
{
    return fwrite(&c,1,1,stream);
}

int fputs(const char *s, FILE *stream)
{
    return fwrite(s,strlen(s),1,stream);
}

int putc(int c, FILE *stream)
{
    return fwrite(&c,1,1,stream);
}

int putchar(int c)
{
    return putc(c,stdout);
}

int puts(const char *s)
{
    return fputs(s,stdout);
}

void __attribute__((constructor)) __stdio_init()
{
    static int __stdio_initialized=0;

    if (__stdio_initialized)
        return;

    int i=0;
    __posix_init();
    for (i=0;i!=MAX_FILES;i++) {
        __files[i].fd = -1;
    }
    __stdio_initialized=1;
}
#endif
