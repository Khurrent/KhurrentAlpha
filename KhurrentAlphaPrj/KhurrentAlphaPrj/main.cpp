#include "FileSeparation.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream ifs;
	ifs.open("README.md",ios_base::in);
	string c;
	
	ifs.close();
	return 0;
}