#include "FileSeparation.h"
#include "Pieces.h"

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

FileSeparation::FileSeparation()
{
	/* initialize file split size */
	this->_splitSize = 0;
	/* initialize file size */
	this->_orgFileSize = 0;
}

FileSeparation::~FileSeparation()
{
	cout << "file Size : " << this->_orgFileSize << endl;
	cout << "splitSize : " << this->_splitSize << endl;
	cout << "file Name : " << this->_address << endl;
	cout << _getNumberOfSplits() << endl;
}

void FileSeparation::setFileAddress(char *addr)
{
	this->_address = addr;
	/* initialize file split size */
	this->_splitSize = 0;
	/* initialize file size */
	this->_orgFileSize = 0;
}

void FileSeparation::setSplitSize(size_t size)
{
	this->_splitSize = size;
}

bool FileSeparation::fileSplit()
{
	FILE *fp;
	/* open and read file */
	_readFile(fp);
	/* dynamic allocation for piece storage */
	this->_fileData = new char[this->_orgFileSize * sizeof(char) + 1];
	/* copy data NOT SPLIT */
	for(size_t i = 0;i < this->_orgFileSize + 1; i++) {
		fread((void *)this->_fileData, sizeof(char), sizeof(this->_fileData), fp); 
	}
	fclose(fp);
	delete this->_fileData;
	return false;
}

unsigned long long int FileSeparation::getFileSize()
{
	return this->_orgFileSize;
}

unsigned int FileSeparation::getNumberOfSplits()
{
	return _numberOfSplits;
}

Pieces FileSeparation::pieceTransition(bool type)
{
	Pieces p;
	p.setPieceSize(this->_splitSize);
	p.setNumberofPiece(this->_numberOfSplits);

	/* send whole pieces */
	if(type == true) {
	}
	/* send only one piece */
	else {
	}

	return p;
}

void FileSeparation::_readFile(FILE *&fp)
{
	/* open File */
	fp = fopen(this->_address, "rb");
	if(!fp) {
		cout << "File doesn't exist" << endl;
		exit(100);
	}
	/* get Position to calculate File Size */
	this->_orgFileSize = _getFileSize(fp);
}


unsigned long long int FileSeparation::_getFileSize(FILE *&fp)
{
	unsigned long long int fSize;
	/* get File size. Move to EOF */
	fseek(fp, 0, SEEK_END);
	/* get File Size */
	fSize = ftell(fp);
	/* rewind current position to the front */
	rewind(fp);

	/* return file size */
	return fSize;
}

unsigned int FileSeparation::_getNumberOfSplits()
{
	/* the data types are each different though, */
	/* it is okay because when you divide, */
	/* the result will fit on the data type (unsigned int) */
	this->_numberOfSplits = this->_orgFileSize / this->_splitSize;
	return this->_numberOfSplits;
}