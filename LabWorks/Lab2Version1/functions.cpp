#include "functions.h"

void push(char *&str, FileRows *&pHeader)
{
	FileRows *pNewHeader = new FileRows;
	int lengthStr = strlen(str);
	// III method
	//pNewHeader->row = new char[strlen(str)]; // *sizeof(char) need or not?
	//strcpy(pNewHeader->row, str);

	// II Method
	pNewHeader->row = new char[lengthStr];
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

	delete pPopValue;
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
		cout << (pHeaderCopy->addr)->row;
		pLast = pHeaderCopy;
		pHeaderCopy = pHeader;
	}
	cout << pHeaderCopy->row;

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
	{
		pLast = pLast->addr;
		++counter;
	}

	while (NULL != pHeaderCopy)
	{
		char *str = new char[(sizeof pHeaderCopy->row)+3];
		_itoa_s(counter, str, sizeof(str),10);
		str[1] = ':';
		str[2] = ' ';
		int length = strlen(str);
		for (int i = 3; i < length; ++i)
		{
			str[i] = (pHeaderCopy->row)[i - 3];
		}
		strcpy_s(pHeaderCopy->row, sizeof(pHeaderCopy->row),str);
		pHeaderCopy = pHeaderCopy->addr;
		--counter;
	}
}

FileRows *&loadFileToStack(char* fileAddr)
{
	fstream F(fileAddr, ios::binary | ios::in);
	if (!F) {
		cout << "Can't open the file.";
		exit(1);
	}

	static FileRows *pHeader = NULL;

	char symFromFile;
	int lineSize = 0;
	int allLinesSize = 0;

	while (!F.eof())
	{
		F.seekg(allLinesSize, ios::beg);
		
		lineSize = 0;
		while (((symFromFile = F.get()) != 10) && !F.eof())
			++lineSize;
			
		if (lineSize == 0)
			break;
		F.seekg(allLinesSize, ios::beg);
		
		
		char *str = new char[lineSize];
		F.read(str, lineSize);
		str[lineSize-1] = '\0';
		push(str, pHeader);
		allLinesSize += (lineSize+1);
		delete str; //II method
	}

	return pHeader;

	F.close();
}