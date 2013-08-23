#include "FileSeparation.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

FileSeparation::FileSeparation()
{
}

FileSeparation::~FileSeparation()
{
	cout << _address;
}

void FileSeparation::setFileAddress(char *addr)
{
	this->_address = addr;
}

void FileSeparation::setSplitSize(int size)
{
	this->_pieceSize = size;
}

bool FileSeparation::fileSplit()
{
	return false;
}