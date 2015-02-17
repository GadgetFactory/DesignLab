
extern unsigned int __bss_start__,__bss_end__;
extern unsigned int ___ctors, ___ctors_end;
extern char __end__;
static char *start_brk = &__end__;

extern void _Z4loopv();
extern void _Z5setupv();

void ___clear_bss()
{
	unsigned int *ptr =  &__bss_start__;
	while (ptr!=&__bss_end__) {
		*ptr = 0;
		ptr++;
	}
}

void ___do_global_ctors()
{
	unsigned int *ptr = &___ctors;
	while (ptr!=&___ctors_end) {
		((void(*)(void))(*ptr))();
		ptr++;
	}
}

void __cxa_pure_virtual()
{
	// Abort here.
}

void exit(){
}

#ifndef NOMAIN
int main(int argc, char **argv)
{
	_Z5setupv();
	while (1) {
		_Z4loopv();
	}
}
#endif

void __attribute__((noreturn)) _premain(void)
{
#ifndef NOCLEARBSS
    ___clear_bss();
#endif
	___do_global_ctors();
	main(0,0);
	while(1);
}


#define PAGESIZE 4096
static int __brk_initialised=0;
static void *mend = 0;

static void brk__initialise()
{
    unsigned ptr = (unsigned)&__end__;
    ptr+=(PAGESIZE-1);
    ptr&=~(PAGESIZE-1);

    mend = (void*)ptr;

    __brk_initialised=1;
}

void *sbrk(int increment)
{
    if (!__brk_initialised)
        brk__initialise();

    void *ret = (void*)mend;

    increment += (PAGESIZE-1);
    increment &= (~(PAGESIZE-1));

    mend=(void*)((unsigned char*)mend + increment);
#ifdef DEBUG_SBRK

    outbyte('S');
    outbyte('B');
    outbyte('R');
    outbyte('K');
    outbyte(' ');
    printhex((unsigned)increment);
    outbyte(' ');
    printhex((unsigned)ret);
    outbyte('\n');
#endif
    return ret;
}
