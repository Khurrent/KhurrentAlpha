#ifndef _FILE_SEPARATION_H
#define _FILE_SEPARATION_H

#include "Pieces.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class FileSeparation
{
public:
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

	char* getPiece(int idx);


	Pieces pieceTransition();

	/* Summarize pieces infomations to transit*/
	Pieces pieceTransition(bool type);

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