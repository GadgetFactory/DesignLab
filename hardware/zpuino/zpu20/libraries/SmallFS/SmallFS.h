#ifndef __SMALLFS_H__
#define __SMALLFS_H__

#ifdef __linux__

#else
#include "zpuino.h"
#include "Arduino.h"
#endif

/** SmallFS filesystem magic */
#define SMALLFS_MAGIC 0x50411F50

#ifndef SEEK_SET
# define SEEK_SET   0
# define SEEK_CUR  1
# define SEEK_END  2
#endif

struct smallfs_header {
	unsigned int magic /** big-endian, magic number **/;
	unsigned int numfiles;
}__attribute__((packed));

struct smallfs_entry {
	unsigned int offset;
	unsigned int size;
	unsigned char namesize;
	char name[0];
} __attribute__((packed));

#ifndef ZPU15
extern "C" void *bootloaderdata;
struct boot_t {
	unsigned int spiend;
	unsigned int signature;
	unsigned char * vstring;
};
#endif

/**
 * @brief SmallFS File Class
 */
class SmallFSFile
{
public:
	SmallFSFile(): flashoffset(-1),seekpos(0) {}
	SmallFSFile(unsigned o,unsigned size): flashoffset(o),filesize(size),seekpos(0) {}
	/**
	 * @brief Check if file was successfuly opened.
	 * @return true on success, false otherwise
     */
	bool valid() { return flashoffset>=0;}//!=-1; }

	/**
	 * @brief Read a chunk of data from file.
	 * @param buf The buffer where to store data
	 * @param size The number of bytes to read from file.
	 * @return The number of bytes read, 0 for EOF.
	 */
	int read(void *buf, int size);
	/**
	 * @brief Seek current file position
	 * @param pos The required position
	 * @param whence Where to perform seek. Either SEEK_SET, SEEK_CUR or SEEK_END
	 */
	int seek(int pos, int whence);
	/**
	 * @brief Get the file size.
	 * @return The file size.
     */
	inline int size() const { return filesize; }
	/**
	 * @brief Read a chunk of data from file, using a callback function.
	 * The function will be called for every byte read.
	 * @param size The number of bytes to read from file.
	 * @param callback The callback function to call
	 * @param data The data parameter to pass to callback function.
	 * @return The number of bytes read, 0 for EOF.
	 */
	
	int readCallback(int size, void (*callback)(unsigned char, void*), void *data);

        /**
         * @brief Read all contents into memory. Uses malloc().
         */
        void *readIntoMemory();



	/**
	 * @brief Read a single byte
	 */
	unsigned readByte();

        /**
	 * @brief Get flass offset for this file
         */
	inline int getOffset() const { return flashoffset; }
	inline int getSize() const { return filesize; }

private:
	int flashoffset;
	int filesize;
	int seekpos;
};

/* @brief SmallFS entry */

class SmallFS_class;

/**
 * @brief SmallFSEntry represents a file entry on the SmallFS
 *
 * SmallFSEntry represents a file entry on the SmallFS and allows you to
 * iterate through the present files.
 *
 *
 */
class SmallFSEntry
{
	friend class SmallFS_class;
public:
	SmallFSEntry(): m_offset(0) {}
	/**
	 * @brief Check if this entry is valid.
	 */
	bool valid() const { return m_offset>0; }

	bool hasNext() const;
	bool equals(const char *name);
	bool endsWith(const char *end);
	bool startsWith(const char *end);

	void getName(char *dest);
	SmallFSFile open();
	SmallFSEntry&operator++(int);
	SmallFSEntry&operator--();

protected:
	SmallFSEntry(unsigned offset, unsigned idx): m_offset(offset),m_index(idx) {}
private:
	unsigned m_offset;
	unsigned m_index;
};

/**
 * @brief Main filesystem class
 */
class SmallFS_class {
public:
	/**
	 * @brief Initialize the SmallFS filesystem
	 * @return 0 on success, -1 otherwise
	 */
	static int begin();

protected:
	static void spi_disable()
	{
#ifndef __linux__
		digitalWrite(SPI_FLASH_SEL_PIN,HIGH);
#endif
	}

	static void spi_enable()
	{
#ifndef __linux__
		digitalWrite(SPI_FLASH_SEL_PIN,LOW);
#endif
	}

	static inline void spiwrite(unsigned int i)
	{
#ifndef __linux__
		SPIDATA=i;
#endif
	}

	static inline unsigned int spiread()
	{
#ifndef __linux__
		return SPIDATA;
#else
		return 0;
#endif
	}

	static inline void spiwrite(register_t datareg, unsigned int i)
	{
#ifndef __linux__
		*datareg=i;
#endif
	}

	static inline unsigned int spiread(register_t datareg)
	{
#ifndef __linux__
		return *datareg;
#else
		return 0;
#endif
	}
public:
	static unsigned int getCount() { return hdr.numfiles; }
	static unsigned int getFSStart() { return fsstart; }

public:
//protected:
//	friend class SmallFSFile;
	static void read(unsigned address, void *target, unsigned size);
	static void seek(unsigned address) { seek_if_needed(address); }
	static unsigned readByte(unsigned address);
public:
	/**
	 * @brief Open a file on the filesystem.
	 * @param name The file name
	 * @return A new SmallFSFile object. You should call valid() to check
	 * if file was successfully open.
	 */
	static SmallFSFile open(const char *name);
	static SmallFSFile openByOffset(unsigned offset);
	static SmallFSEntry getFirstEntry();
	static void loadSketch(const char *name);
private:
	static void seek_if_needed(unsigned address);

	static struct smallfs_header hdr;
	static unsigned fsstart;
	static unsigned offset;
	static bool can_load_sketches;
#ifdef __linux__
	static int fd;
#endif
};

extern SmallFS_class SmallFS;

#endif
