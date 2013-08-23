#include "FileSeparation.h"

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

FileSeparation::FileSeparation()
{
	/* initialize file split size */
	this->_splitSize = 0;
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
	this->_splitSize = 0;
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
	return _orgFileSize / _splitSize;
}