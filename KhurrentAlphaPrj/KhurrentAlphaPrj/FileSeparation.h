#ifndef _FILE_SEPARATION_H
#define _FILE_SEPARATION_H

class FileSeparation
{
public:
	//split units(16KB ~ 16MB to be BYTES) 
	static const int KBYTE_16		=	16 * 1024;
	static const int KBYTE_32		=	32 * 1024;
	static const int KBYTE_64		=	64 * 1024;
	static const int KBYTE_128		=	128 * 1024;
	static const int KBYTE_256		=	256 * 1024;
	static const int KBYTE_512		=	512 * 1024;
	static const int KBYTE_1024		=	1024 * 1024;
	static const int KBYTE_2048		=	2048 * 1024;
	static const int KBYTE_4096		=	4096 * 1024;
	static const int KBYTE_8192		=	8192 * 1024;
	static const int KBYTE_16384		=	16384 * 1024;

	//constructors & destructor
	FileSeparation();
	FileSeparation(char *addr) : _address(addr) {}
	FileSeparation(char *addr, int pieceSize) : _address(addr), _pieceSize(pieceSize) {}
	~FileSeparation();

	void setFileAddress(char *addr);
	void setSplitSize(int size);
	bool fileSplit();
private:
	char *_address;
	int _pieceSize;
};

#endif