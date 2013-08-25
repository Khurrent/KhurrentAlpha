#include "Pieces.h"

#include <iostream>

Pieces::Pieces()
{
	this->_piece = nullptr;
}

Pieces::~Pieces()
{
	if(this->_piece)
		delete this->_piece;
}

void Pieces::setPieceSize(size_t size)
{
	this->_size = size;
}

void Pieces::setNumberofPiece(int numberOfPiece)
{
	this->_numberOfPiece = numberOfPiece;
}

void Pieces::pieceSetInit()
{
	this->_piece = new pieceSet[_numberOfPiece];
}

void Pieces::printStatus()
{
	std::cout << "piece size : " << this->_size << std::endl;
	std::cout << "piece numb : " << this->_numberOfPiece << std::endl;
}