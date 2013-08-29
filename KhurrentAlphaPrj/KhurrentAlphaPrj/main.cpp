#include "FileSeparation.h"
#include "Pieces.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	FileSeparation fs;
	fs.setAddress("test.txt");
	fs.setPieceSize(Pieces::KBYTE_16);
	fs.exec();
	fs.printStatus();
	
	Pieces* ps = new Pieces;

	fs.pieceTransit(ps);
	ps->printStatus();


	return 0;
}	