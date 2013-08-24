#ifndef _FILE_SEPARATION_H
#define _FILE_SEPARATION_H

#include "Pieces.h"

<<<<<<< HEAD
#include <iostream>
=======
>>>>>>> origin/hoon
#include <stdlib.h>
#include <stdio.h>

class FileSeparation
{
public:
<<<<<<< HEAD
	/* split units(16KB ~ 16MB to be BYTES) */
	static const size_t KBYTE_16		=	16 * 1024;
	static const size_t KBYTE_32		=	32 * 1024;
	static const size_t KBYTE_64		=	64 * 1024;
	static const size_t KBYTE_128		=	128 * 1024;
	static const size_t KBYTE_256		=	256 * 1024;
	static const size_t KBYTE_512		=	512 * 1024;
	static const size_t KBYTE_1024		=	1024 * 1024;
	static const size_t KBYTE_2048		=	2048 * 1024;
	static const size_t KBYTE_4096		=	4096 * 1024;
	static const size_t KBYTE_8192		=	8192 * 1024;
	static const size_t KBYTE_16384		=	16384 * 1024;

=======
>>>>>>> origin/hoon
	/* constructors & destructor */
	FileSeparation();
	FileSeparation(char *addr) : _address(addr) {}
	FileSeparation(char *addr, int splitSize) : _address(addr), _splitSize(splitSize) {}
	~FileSeparation();

	void setFileAddress(char *addr);
	void setSplitSize(size_t size);
	bool fileSplit();
	unsigned long long int getFileSize();
	unsigned int getNumberOfSplits();
<<<<<<< HEAD
<<<<<<< HEAD
	char* getPiece(int idx);
=======

	Pieces pieceTransition();
>>>>>>> origin/hoon
=======
	/* Summarize pieces infomations to transit*/
	Pieces pieceTransition(bool type);
>>>>>>> origin/hoon
private:
	char *_fileData;
	char *_address;
	size_t _splitSize;
	unsigned long long int _orgFileSize;
	unsigned int _numberOfSplits;

	/* readFile (open) */
	void _readFile(FILE *&fp);
	/* get file size using fseek() */
	unsigned long long int _getFileSize(FILE *&fp);
	unsigned int _getNumberOfSplits();
};

#endif