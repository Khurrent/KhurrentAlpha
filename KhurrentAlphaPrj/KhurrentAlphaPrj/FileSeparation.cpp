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
	cout << "file Name : " << this->_address << endl;
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

	readFile(fp);
	fclose(fp);
	return false;
}

void FileSeparation::readFile(FILE *&fp)
{
	/* open File */
	fp = fopen(this->_address, "rb");
	/* get Position to calculate File Size */
	this->_orgFileSize = getFileSize(fp);
}


unsigned long long int FileSeparation::getFileSize(FILE *&fp)
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