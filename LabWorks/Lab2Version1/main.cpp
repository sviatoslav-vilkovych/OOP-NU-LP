#include "functions.h"

void main()
{
	FileRows *pHeader;
	char fileAddr[80];

	cout << "Please enter file location: ";
	cin >> fileAddr;

	pHeader = loadFileToStack(fileAddr);
	renumber(pHeader);
	purge(pHeader);
}