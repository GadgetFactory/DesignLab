#include <new.h>
#include <inttypes.h>
#include <string.h>
#include <new>

#ifdef ZPULOWMEM

extern "C" {
    extern void *__end__;
    static void *alloc_buffer = &__end__;
    void * malloc(int size)
    {
        void *ret = alloc_buffer;
        /* Align */
        alloc_buffer = (void*)((unsigned)alloc_buffer + size);
        alloc_buffer = (void*)(((unsigned)alloc_buffer + 3) & ~3);
        return ret;
    }
    void free(void*)
    {
    }
    void *realloc(void *ptr, int size) {
        void *newptr = malloc(size);
        if(newptr)
        {
            if(ptr)
                memcpy(newptr, ptr, size);
            return newptr;
        }
        return NULL;
    }
};

void * operator new(size_t size)
{
  return malloc(size);
}

void operator delete(void * ptr)
{
  free(ptr);
} 

#else
#include <stdlib.h>

void * operator new(size_t size)
{
  return malloc(size);
}

void operator delete(void * ptr)
{
  free(ptr);
} 
#if 0
int __cxa_guard_acquire(__guard *g) {return !*(char *)(g);};
void __cxa_guard_release (__guard *g) {*(char *)g = 1;};
void __cxa_guard_abort (__guard *) {}; 

void __cxa_pure_virtual(void) {};
#endif

#endif

