#ifndef __DEVICE_H__
#define __DEVICE_H__

#include <sys/types.h>
#include <sys/stat.h>
#include <config.h>

#ifndef NOPOSIX
#define HAVE_ZFDEVICE

#ifdef __cplusplus
extern "C" {
#endif

struct zfops {
    void *(*open)(const char *path);
    void (*close)(void*);
    ssize_t (*read)(void*, void *target, size_t size);
    ssize_t (*write)(void*, const void *source, size_t size);
    int (*seek)(void*,int,int);
    int (*fstat)(void*,struct stat *buf);
};

struct zfdevops {
    ssize_t (*read)(void*, void *target, size_t size);
    ssize_t (*write)(void*, const void *source, size_t size);
};
struct devops;

int zfRegisterFileBackend(const char *name, struct zfops *ops);
int zfRegisterDevice(const char *name, struct zfdevops *ops, void *data);


struct zfops *zfFindBackend(const char *name);

#ifdef __cplusplus
}
#endif

#endif

#endif
