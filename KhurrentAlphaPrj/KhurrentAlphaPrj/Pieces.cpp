#include "Pieces.h"

#include <iostream>

Pieces::Pieces()
{
	this->_piece = nullptr;
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
	/* +1 is intended for the very last and imperfect piece. */
	this->_piece = new pieceSet[this->_numberOfPiece + 1];
	for(int i=0;i<this->_numberOfPiece;i++)
	{
		this->_piece[i].dataPieces = new char[this->_pieceSize];
		this->_piece[i].idx = i;
	}
	this->_piece[this->_numberOfPiece].dataPieces = new char[this->_lastPieceSize];
	this->_piece[this->_numberOfPiece].idx = this->_numberOfPiece;
}

bool Pieces::setPieceData()
{
	if(!this->_piece) return true;

	

	return false;
}

void Pieces::printStatus()
{
	std::cout << "piece size : " << this->_pieceSize << std::endl;
	std::cout << "piece numb : " << this->_numberOfPiece << std::endl;
}