#include "functions.h"

void main()
{
	FileRows *pHeader;
	char fileLoc[80];
	printf("%s", "Please enter file location: ");
	scanf("%s", fileLoc);

	pHeader = loadFileToStack(fileLoc);
	renumber(pHeader);
	purge(pHeader);

}