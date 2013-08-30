#include "Pieces.h"

#include <iostream>
using namespace std;

Pieces::Pieces()
{
	this->_piece			= nullptr;
	this->_pieceSize		= 0;
	this->_lastPieceSize	= 0;
	this->_numberOfPiece	= 0;
	this->_fileSize			= 0;
	this->_address			= nullptr;
}

Pieces::~Pieces()
{
	if(this->_piece)
	{
		for(int i=0;i<this->_numberOfPiece + 1; i++)
			delete[] this->_piece[i].dataPieces;
		delete[] this->_piece;
	}
}

void Pieces::setPieceSize(size_t size)
{
	this->_pieceSize = size;
}

void Pieces::setLastPieceSize(size_t size)
{
	this->_lastPieceSize = size;
}

void Pieces::setNumberofPiece(int numberOfPiece)
{
	this->_numberOfPiece = numberOfPiece;
}

void Pieces::setFileSize(unsigned long long int fileSize)
{
	this->_fileSize = fileSize;
}

void Pieces::setFileAddress(char *address)
{
	this->_address = address;
}

void Pieces::pieceSetInit()
{
	/* dynamic allocation */
	/* +1 is intended for the very last and imperfect piece. */
	this->_piece = new pieceSet[this->_numberOfPiece+1];
	for(int i=0;i<this->_numberOfPiece;i++)
	{
		this->_piece[i].dataPieces = new char[this->_pieceSize+1];
		this->_piece[i].dataPieces[this->_pieceSize] = '\0';
		this->_piece[i].size = this->_pieceSize;
	}
	this->_piece[this->_numberOfPiece].dataPieces = new char[this->_lastPieceSize+1];
	this->_piece[this->_numberOfPiece].dataPieces[this->_lastPieceSize] = '\0';
	this->_piece[this->_numberOfPiece].size = this->_lastPieceSize;
}

bool Pieces::setPieceData(int idx, char *data, int size)
{
	if(!this->_piece) return true;

	this->_piece[idx].dataPieces = new char[size];
	strcpy(this->_piece[idx].dataPieces, data);

	return false;
}

void Pieces::printStatus()
{
	cout << endl;
	cout << this->_piece[0].dataPieces << endl;
}