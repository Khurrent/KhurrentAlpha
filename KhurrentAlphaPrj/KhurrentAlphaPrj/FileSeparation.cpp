#include "FileSeparation.h"
#include "Pieces.h"

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

FileSeparation::FileSeparation()
{
	/* initialize data */
	this->_address		= nullptr;
	this->_transitData  = nullptr;
	this->_pieceSize	= 0;
	this->_fileSize		= 0;
	this->_fp			= nullptr;
}

FileSeparation::FileSeparation(char *addr)
{
	/* copy address data */
	this->_address		= addr;

	/* initialize data */
	this->_transitData  = nullptr;
	this->_pieceSize	= 0;
	this->_fileSize		= 0;
	this->_fp			= nullptr;

}

FileSeparation::~FileSeparation()
{
	/* if FILE *this->_fp exists, do kill */
	if(this->_fp) fclose(this->_fp);
	/* deletion */
	if(this->_transitData) delete[] this->_transitData;
}

void FileSeparation::setAddress(char *addr)
{
	this->_address = addr;
}

bool FileSeparation::exec()
{
	bool result = this->_readFile();
	if(result == true)
		return true;
	return false;
}


int FileSeparation::getNumberOfPieces()
{
	return this->_numberOfPieces;
}

void FileSeparation::printStatus()
{
	cout << "File Name : " << this->_address << endl;
	cout << "PieceSize : " << this->_pieceSize << endl;
	cout << "File Size : " << this->_fileSize << endl;
	cout << "NoOfpiece : " << this->_numberOfPieces << endl;
	cout << "lastPiece : " << this->_lastPieceSize << endl;
}

void FileSeparation::setPieceSize(size_t size)
{
	this->_pieceSize = size;
}

void FileSeparation::pieceTransit(Pieces *&pieces)
{
	pieces->setPieceSize(this->_pieceSize);
	pieces->setNumberofPiece(this->_numberOfPieces);
	pieces->setLastPieceSize(this->_lastPieceSize);
	pieces->setFileSize(this->_fileSize);
	pieces->setFileAddress(this->_address);

	/* initialize piece set */
	pieces->pieceSetInit();
	
	_savePieces(pieces);
}

bool FileSeparation::_readFile()
{
	/* open File */
	this->_fp = fopen(this->_address, "rb");
	
	if(!this->_fp) {
		cout << "error! file doesn't exist" << endl;
		return true;
	}
	
	/* get file data info */
	this->_getFileSize();
	this->_getNumberOfPieces();
	this->_getLastPieceSize();

	return false;
}

void FileSeparation::_getFileSize()
{
	/* move position to eof */
	fseek(this->_fp, 0, SEEK_END);
	/* get position of eof */
	this->_fileSize = ftell(this->_fp);
	/* move back to the front */
	rewind(this->_fp);
}

void FileSeparation::_getNumberOfPieces()
{
	this->_numberOfPieces = (int)(this->_fileSize / this->_pieceSize);
}

void FileSeparation::_getLastPieceSize()
{
	this->_lastPieceSize = this->_fileSize % this->_pieceSize;
}

void FileSeparation::_savePieces(Pieces *&pieces)
{
	/*
		for()
			_getData(iter);
	*/
}

void FileSeparation::_getData(int nth)
{
	fread(this->_transitData, this->_pieceSize, 1, this->_fp);
	// fseek();
}