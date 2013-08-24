#ifndef _FILE_SEPARATION_H
#define _FILE_SEPARATION_H

#include "Pieces.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

class FileSeparation
{
public:
	FileSeparation();
	FileSeparation(char *addr);
	~FileSeparation();

	void setAddress(char *addr);
	void setPieceSize(size_t size);
	bool exec();
	int  getNumberOfPieces();
	void printStatus();

	void pieceTransit(Pieces *&pieces);
private:
	bool _readFile();
	void _getFileSize();
	void _getNumberOfPieces();
	void _getLastPieceSize();

	char *_address;
	size_t _pieceSize;
	size_t _lastPieceSize;
	unsigned long long int _fileSize;
	int _numberOfPieces;
	FILE *_fp;
};

#endif