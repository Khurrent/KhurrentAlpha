#include "FileSeparation.h"
#include "Pieces.h"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	/* dynamic allocation for multi-threading */
	FileSeparation *fs = new FileSeparation[2];

	fs[0].setAddress("test.txt");
	fs[0].setPieceSize(Pieces::KBYTE_16);
	fs[0].exec();

	fs[1].setAddress("test.msi");
	fs[1].setPieceSize(Pieces::KBYTE_64);
	fs[1].exec();

	Pieces *pieces = new Pieces;
	fs[0].pieceTransit(pieces);

	fs[0].printStatus();
	pieces->printStatus();
	cout << endl;
	fs[1].printStatus();

	delete pieces;
	delete[] fs;


	return 0;
}	