#include "functions.h"

struct FileRows {
	char *row;
	FileRows *addr;

};
void push(FileRows *&pHeader, char *&str)
{
	FileRows *pNewHeader = (FileRows*)malloc(sizeof(FileRows));
	pNewHeader->row = (char*)malloc(sizeof str); // *sizeof(char) need or not?
	pNewHeader->row = str;
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
FileRows *loadFileToStack(char *fileName)
{
	FILE *F = fopen(fileName, "rb");
	FileRows *pHeader = 0;

	if (NULL == F) {
		printf("%s", "Can't open the file.");
		exit(1);
	}

	char symFromFile;
	int lineSize = 0;
	int allLinesSize = 0;
	// PROBLEM START
	for (lineSize = 0; symFromFile = getc(F) != 13 && !feof(F); ++lineSize);
	if (lineSize == 0)
		return pHeader;
	fseek(F, allLinesSize, SEEK_SET);
	allLinesSize += lineSize;
	char *str = (char*)malloc(lineSize + 1);
	fgets(str, lineSize + 1, F);

	pHeader = (FileRows*)malloc(sizeof(FileRows));
	pHeader->row = (char*)malloc(sizeof str); // *sizeof(char) need or not?
	pHeader->row = str;
	pHeader->addr = 0;

	fseek(F, allLinesSize += 2, SEEK_SET);
	// PROBLEM END
	while (!feof(F))
	{
		for (lineSize = 0; symFromFile = getc(F) != 13 && !feof(F); ++lineSize);
		if (lineSize == 0)
			break;
		fseek(F, allLinesSize, SEEK_SET);
		allLinesSize += lineSize;
		str = (char*)malloc(lineSize + 1);
		fgets(str, lineSize + 1, F);
		push(pHeader, str);
		fseek(F, allLinesSize += 2, SEEK_SET);
	}
	fclose(F);

	return pHeader;
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

		char *str = (char*)malloc(sizeof((pLast->addr)->row));
		itoa(counter, str, 10);
		strcat(str, ": ");
		strcat(str, ((pHeaderCopy->addr)->row));
		strcpy(((pHeaderCopy->addr)->row), str);
		// free(str);

		counter = counter + 1;
		pLast = pHeaderCopy;
		pHeaderCopy = pHeader;
	}
	char *str = (char*)malloc(sizeof(pHeaderCopy->row));
	itoa(counter, str, 10);
	strcat(str, ": ");
	strcat(str, (pHeaderCopy->row));
	strcpy((pHeaderCopy->row), str);
	//free(str);
}