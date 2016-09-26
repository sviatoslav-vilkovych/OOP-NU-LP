#include "functions.h"

void main()
{
	FileRows *pHeader;
	char fileAddr[80];

	printf("%s", "Please enter file location: ");
	scanf("%s", fileAddr);

	pHeader = loadFileToStack(fileAddr);
	renumber(pHeader);
	purge(pHeader);
}