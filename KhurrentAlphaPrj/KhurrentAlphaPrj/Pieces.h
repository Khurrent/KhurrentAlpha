#ifndef _PIECES_H
#define _PIECES_H

class Pieces
{
public:
	/* split units(16KB ~ 16MB to be BYTES) */
	static const size_t KBYTE_16		=	16 * 1024;
	static const size_t KBYTE_32		=	32 * 1024;
	static const size_t KBYTE_64		=	64 * 1024;
	static const size_t KBYTE_128		=	128 * 1024;
	static const size_t KBYTE_256		=	256 * 1024;
	static const size_t KBYTE_512		=	512 * 1024;
	static const size_t KBYTE_1024		=	1024 * 1024;
	static const size_t KBYTE_2048		=	2048 * 1024;
	static const size_t KBYTE_4096		=	4096 * 1024;
	static const size_t KBYTE_8192		=	8192 * 1024;
	static const size_t KBYTE_16384		=	16384 * 1024;

	Pieces();
	~Pieces();

	void setPieceSize(size_t size);
	void setLastPieceSize(size_t size);
	void setNumberofPiece(int numberOfPiece);
	void setFileSize(unsigned long long int fileSize);
	void setFileAddress(char *address);
	void pieceSetInit();
	void pieceSetTransit();
	bool setPieceData(int idx, char *data, int size);
	void printStatus();

private:	
	
	struct pieceSet
	{
		int size;
		char *dataPieces;
	};

	pieceSet *_piece;
	
	size_t _pieceSize;
	size_t _lastPieceSize;
	int _numberOfPiece;
	unsigned long long int _fileSize;
	char *_address;
};

#endif