#ifndef _FILE_SEPARATION_H
#define _FILE_SEPARATION_H

class FileSeparation
{
public:
	//split units(16KB ~ 16MB)
	static const int KBYTE_16		=	16;
	static const int KBYTE_32		=	32;
	static const int KBYTE_64		=	64;
	static const int KBYTE_128		=	128;
	static const int KBYTE_256		=	256;
	static const int KBYTE_512		=	512;
	static const int KBYTE_1024		=	1024;
	static const int KBYTE_2048		=	2048;
	static const int KBYTE_4096		=	4096;
	static const int KBYTE_8192		=	8192;
	static const int KBYTE_16384		=	16384;

	//constructors & destructor
	FileSeparation();
	FileSeparation(char *addr) : address(addr) {}
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