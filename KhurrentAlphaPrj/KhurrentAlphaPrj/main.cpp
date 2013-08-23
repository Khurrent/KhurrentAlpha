#include "FileSeparation.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	FileSeparation *fs = new FileSeparation;
	
	fs->setFileAddress("test.txt");
	fs->setSplitSize(FileSeparation::KBYTE_16);
	fs->fileSplit();
	
	delete fs;

	return 0;
}	