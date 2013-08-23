#ifndef _FILE_SEPARATION_H
#define _FILE_SEPARATION_H

class FileSeparation
{
public:
	const int KBYTE_16		=	16;
	const int KBYTE_32		=	32;
	const int KBYTE_64		=	64;
	const int KBYTE_128		=	128;
	const int KBYTE_256		=	256;
	const int KBYTE_512		=	512;
	const int KBYTE_1024		=	1024;
	const int KBYTE_2048		=	2048;
	const int KBYTE_4096		=	4096;
	const int KBYTE_8192		=	8192;
	const int KBYTE_16384		=	16384;

	FileSeparation();
	FileSeparation(char *);
private:
	int p;
};

#endif