#include "functions.h"



void push(char *&str, FileRows *&pHeader)
{
	FileRows *pNewHeader = (FileRows*)malloc(sizeof(FileRows));
	int lengthStr = strlen(str);
	// III method
	//pNewHeader->row = (char*)malloc(strlen(str)); // *sizeof(char) need or not?
	//strcpy(pNewHeader->row, str);

	// II Method
	pNewHeader->row = (char*)malloc(lengthStr*sizeof(char)); // *sizeof(char) need or not?
	int lengthRow = strlen(pNewHeader->row);
	for (int i = 0; i < lengthStr; ++i)
			(pNewHeader->row)[i] = str[i];
	for (int i = lengthStr; i < lengthRow; ++i)
		(pNewHeader->row)[i] = 0;
	
	// I method
	// pNewHeader->row = str;

	pNewHeader->addr = pHeader;
	pHeader = pNewHeader;
}
void pop(FileRows *&pHeader)
{
	FileRows *pPopValue = pHeader;
	pHeader = pHeader->addr;
	free(pPopValue);
}
void purge(FileRows *&pHeader)
{
	// output
	FileRows *pHeaderCopy = pHeader;
	FileRows *pLast = pHeader;
	while (pLast->addr != 0)
		pLast = pLast->addr;

	while (pLast != pHeader)
	{
		while (pHeaderCopy->addr != pLast)
		{
			pHeaderCopy = pHeaderCopy->addr;
		}
		printf("%s\n", (pHeaderCopy->addr)->row);
		pLast = pHeaderCopy;
		pHeaderCopy = pHeader;
	}
	printf("%s\n", pHeaderCopy->row);

	//clear memory
	while (pHeader != 0)
	{
		pop(pHeader);
	}
}
void renumber(FileRows *&pHeader)
{
	FileRows *pHeaderCopy = pHeader;
	FileRows *pLast = pHeader;
	int counter = 1;
	while (pLast->addr != 0)
		pLast = pLast->addr;

	while (pLast != pHeader)
	{
		while (pHeaderCopy->addr != pLast)
		{
			pHeaderCopy = pHeaderCopy->addr;
		}

		char *str = (char*)malloc(sizeof((pHeaderCopy->addr)->row));
		itoa(counter, str, 10);
		strcat(str, ": ");
		strcat(str, ((pHeaderCopy->addr)->row));
		strcpy((pHeaderCopy->addr)->row,str);
		

		counter = counter + 1;
		pLast = pHeaderCopy;
		pHeaderCopy = pHeader;
	}
	char *str = (char*)malloc(sizeof(pHeaderCopy->row)*sizeof(char));
	itoa(counter, str, 10);
	strcat(str, ": ");
	strcat(str, (pHeaderCopy->row));
	strcpy(pHeaderCopy->row, str);
	
}

FileRows *&loadFileToStack(char* fileAddr)
{
	FILE *F = fopen(fileAddr, "rb");
	if (NULL == F) {
		printf("%s", "Can't open the file.");
		exit(1);
	}

	FileRows *pHeader = NULL;

	char symFromFile;
	int lineSize = 0;
	int allLinesSize = 0;

	while (!feof(F))
	{
		for (lineSize = 0; symFromFile = getc(F) != 13 && !feof(F); ++lineSize);
		if (lineSize == 0)
			break;
		fseek(F, allLinesSize, SEEK_SET);
		allLinesSize += lineSize;
		char *str = (char*)malloc((lineSize + 1)*sizeof(char));
		fgets(str, lineSize + 1, F);
		push(str, pHeader);
		fseek(F, allLinesSize += 2, SEEK_SET);
		
		free(str); //II method
	}

	return pHeader;
}

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