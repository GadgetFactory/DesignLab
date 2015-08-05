#include "SmallFS.h"
#include <string.h>

#ifdef __linux__

#include <fcntl.h>
#include <unistd.h>
#include <endian.h>
#include <stdio.h>
#include <strings.h>

#define BE32(x) be32toh(x)

#else

#include "Arduino.h"
#include "zfdevice.h"


#define BE32(x) x

#endif

#undef SMALLFSDEBUG

#ifdef HAVE_ZFDEVICE
static void zf_register_smallfs();
#endif

int SmallFS_class::begin()
{

#ifdef __linux__
	fsstart = 0;
	fd = ::open("smallfs.dat",O_RDONLY);
	if (fd<0) {
		perror("Cannot open smallfs.dat");
		return -1;
	}
#else
	struct boot_t *b = (struct boot_t*)bootloaderdata;
	fsstart = b->spiend;
	/* Check for >1.9 bootloader */
	if (b->signature==0xb00110ad ) {
		can_load_sketches=1;
	} 

#endif
	offset = 0xffffffff;

	read(fsstart, &hdr,sizeof(hdr));

#ifdef SMALLFSDEBUG

	unsigned debug;

	Serial.print("Read magic ");
	Serial.println(hdr.magic);
	Serial.print("SPI end ");
	Serial.println(fsstart);

	Serial.print("Bdata at ");
	Serial.println((unsigned)b);
	// Test read

	read(fsstart - 8, &debug,sizeof(debug));
	Serial.print("DD1 ");
	Serial.println(debug);
	read(&debug,sizeof(debug));
	Serial.print("DD2 ");
	Serial.println(debug);
	read(&debug,sizeof(debug));
	Serial.print("DD3 ");
	Serial.println(debug);

#endif
    /*
	if(SMALLFS_MAGIC==BE32(hdr.magic))
		return 0;

		return -1;
                */
#ifdef HAVE_ZFDEVICE
        zf_register_smallfs();
#endif

        return hdr.magic  - SMALLFS_MAGIC;
}

void SmallFS_class::seek_if_needed(unsigned address)
{
	register_t spibasedata=&SPIDATA;

	if (address!=offset)
	{
		offset = address;
		spi_disable();
		spi_enable();
#ifdef SMALLFSDEBUG
		Serial.print("Seeking to ");
		Serial.println(address);
#endif
		/*
		spiwrite(spibasedata,0x0B);
		spiwrite(spibasedata,address>>16);
		spiwrite(spibasedata,address>>8);
		spiwrite(spibasedata,address);
		spiwrite(spibasedata,0);
		spiwrite(spibasedata,0); // Read ahead
		*/
		address+=0x0B000000;
		spiwrite(spibasedata+2,address>>16); /* 16-bit write */
		address<<=16;
		spiwrite(spibasedata+6,address); /* 32-bit Includes read-ahead */
	}
}

unsigned SmallFS_class::readByte(unsigned address)
{
	seek_if_needed(address);
	unsigned v = spiread(); // Already cached
	spiwrite(0);
	offset++;
	return v;
}


void SmallFS_class::read(unsigned address, void *target, unsigned size)
{
#ifdef __linux__
	if (fd>=0) {
		::read(fd,target,size);
	}
#else
	seek_if_needed(address);

	unsigned char *p=(unsigned char*)target;
	while (size--) {
		unsigned v = spiread(); // Already cached
		spiwrite(0);
		*p++=v;
		offset++;
	}
#endif
}

SmallFSEntry SmallFS_class::getFirstEntry()
{
	unsigned o = fsstart + sizeof(struct smallfs_header);

	if (BE32(hdr.numfiles)==0)
		return SmallFSEntry();

	return SmallFSEntry(o,0);
}

bool SmallFSEntry::hasNext() const {
	return (m_index+1)<SmallFS_class::getCount();
}

bool SmallFSEntry::equals(const char *name){
	struct smallfs_entry e;
	char buf[256];
	SmallFS_class::read(m_offset, &e,sizeof(struct smallfs_entry));
	SmallFS_class::read( m_offset + sizeof(struct smallfs_entry), buf, e.namesize);
	buf[e.namesize] = '\0';
	return (strcmp(name,buf)==0);
}

bool SmallFSEntry::endsWith(const char *name)
{
	struct smallfs_entry e;
	char buf[256];
	SmallFS_class::read(m_offset, &e,sizeof(struct smallfs_entry));
	SmallFS_class::read( m_offset + sizeof(struct smallfs_entry), buf, e.namesize);
	buf[e.namesize] = '\0';
	unsigned l = strlen(name);
	if (l>e.namesize)
		return false;
	char *p = buf + e.namesize - l;
	return (strcmp(name,p)==0);
}

void SmallFSEntry::getName(char *name)
{
	struct smallfs_entry e;
	SmallFS_class::read( m_offset, &e,sizeof(struct smallfs_entry));
	SmallFS_class::read( m_offset + sizeof(struct smallfs_entry), name, e.namesize);
	name[e.namesize] = '\0';
}

bool SmallFSEntry::startsWith(const char *name)
{
	struct smallfs_entry e;
	char buf[256];
	SmallFS_class::read( m_offset, &e,sizeof(struct smallfs_entry));
	SmallFS_class::read( m_offset + sizeof(struct smallfs_entry), buf, e.namesize);
	buf[e.namesize] = '\0';
	return (strncmp(name,buf,strlen(name))==0);
}

SmallFSFile SmallFSEntry::open() {
	return SmallFS_class::openByOffset(m_offset);
};

SmallFSEntry &SmallFSEntry::operator++(int) {
	if (hasNext()) {
		struct smallfs_entry e;
		m_index++;
		/* Recompute offset */
		SmallFS_class::read(m_offset, &e,sizeof(struct smallfs_entry));
		m_offset+=sizeof(struct smallfs_entry);
		m_offset+=e.namesize;
	}
	return *this;
}

SmallFSFile SmallFS_class::openByOffset(unsigned offset)
{
	struct smallfs_entry e;
	read(offset, &e,sizeof(struct smallfs_entry));
	seek_if_needed(BE32(e.offset) + fsstart);
	return SmallFSFile(BE32(e.offset) + fsstart, BE32(e.size));
}

SmallFSFile SmallFS_class::open(const char *name)
{
	/* Start at root offset */
	unsigned o = fsstart + sizeof(struct smallfs_header);
	unsigned char buf[256];
	struct smallfs_entry e;

	int c;

	for (c=BE32(hdr.numfiles); c; c--) {

		read(o, &e,sizeof(struct smallfs_entry));
		o+=sizeof(struct smallfs_entry);

		read(o, buf,e.namesize);
		o+=e.namesize;

		buf[e.namesize] = '\0';
		/* Compare */
		if (strcmp((const char*)buf,name)==0) {
			
			// Seek and readahead
			seek_if_needed(BE32(e.offset) + fsstart);

			return SmallFSFile(BE32(e.offset) + fsstart, BE32(e.size));
		}
	}
	// Reset offset.
	offset=(unsigned)-1;

	return SmallFSFile();
}

int SmallFSFile::read(void *buf, int s)
{
	if (!valid())
		return -1;

	if (seekpos==filesize)
		return 0; /* EOF */

	if (s + seekpos > filesize) {
		s = filesize-seekpos;
	}
	SmallFS.read(seekpos + flashoffset, buf,s);

	seekpos+=s;
	return s;
}

void *SmallFSFile::readIntoMemory()
{
    void *ret = malloc( getSize() );

    if (NULL==ret)
        return NULL;

    read(ret, getSize());

    return ret;
}

int SmallFSFile::readCallback(int s, void (*callback)(unsigned char, void*), void *data)
{
	unsigned char c;
	int save_s;

	if (!valid())
		return -1;

	if (seekpos==filesize)
		return 0; /* EOF */

	if (s + seekpos > filesize) {
		s = filesize-seekpos;
	}
#ifdef SMALLFSDEBUG
	Serial.print("Will read ");
	Serial.print(s);
	Serial.print(" bytes from file at offset ");
	Serial.print(flashoffset);
	Serial.print(" seekpos is ");

	Serial.println(seekpos);
#endif

	//SmallFS.spi_enable();

	//SmallFS.startread( seekpos + flashoffset );
	save_s = s;
	unsigned tpos = seekpos + flashoffset;
	seekpos += s;

	while (s--) {
		c=SmallFS.readByte(tpos++);
		callback(c,data);
	}

	return save_s;
}

int SmallFSFile::seek(int pos, int whence)
{
	int newpos;

	if (whence==SEEK_SET)
		newpos = pos;
	else if (whence==SEEK_CUR)
		newpos = seekpos + pos;
	else
		newpos = filesize + pos;

	if (newpos>filesize)
		newpos=filesize;

	if (newpos<0)
		newpos=0;

	seekpos=newpos;
	SmallFS.seek(seekpos + flashoffset);

        return newpos;
}

void SmallFS_class::loadSketch(const char *name)
{
	unsigned *lc = (unsigned*)0x38;
	void (*load_sketch)(unsigned offset, unsigned size);
	if (!can_load_sketches)
		return;

	SmallFSFile f = open(name);
	if (f.valid()) {
		load_sketch = ( void(*)(unsigned,unsigned) )*lc;
#ifdef SMALLFSDEBUG
		Serial.print("Loading sketch at ");
		Serial.print(f.getOffset());
		Serial.print(" size ");
		Serial.println(f.getSize());
#endif
		load_sketch(f.getOffset(), f.getSize());
	}
}

SmallFS_class SmallFS;

bool SmallFS_class::can_load_sketches = 0;
struct smallfs_header SmallFS_class::hdr;
unsigned SmallFS_class::fsstart=0;
unsigned SmallFS_class::offset=0;

#ifdef HAVE_ZFDEVICE

/* ZPUino File Device support */

static void *zf_smallfs_open(const char *path)
{
    SmallFSFile f = SmallFS.open(path);
    if (f.valid()) {
        return new SmallFSFile(f);
    }
    return NULL;
}

static ssize_t zf_smallfs_read(void *ptr, void *dest, size_t size)
{
    SmallFSFile *f = static_cast<SmallFSFile*>(ptr);
    return f->read(dest, size);
}

static ssize_t zf_smallfs_seek(void *ptr, int pos, int whence)
{
    SmallFSFile *f = static_cast<SmallFSFile*>(ptr);
    return f->seek(pos, whence);
}

static struct zfops zf_smallfs_ops = {
    &zf_smallfs_open,
    NULL,
    &zf_smallfs_read,
    NULL,
    &zf_smallfs_seek,
    NULL
};

void zf_register_smallfs()
{
    zfRegisterFileBackend("smallfs", &zf_smallfs_ops);
}

#endif
