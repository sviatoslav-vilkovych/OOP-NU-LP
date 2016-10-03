#include "functions.h"

void push(char *&str, FileRows *&pHeader)
{
	FileRows *pNewHeader = new FileRows;
	int lengthStr = strlen(str);
	
	pNewHeader->row = new char[lengthStr+1];
	
	for (int i = 0; i < lengthStr; ++i)
		(pNewHeader->row)[i] = str[i];
	(pNewHeader->row)[lengthStr] = '\0';

	

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
		cout << (pHeaderCopy->addr)->row << endl;
		pLast = pHeaderCopy;
		pHeaderCopy = pHeader;
	}
	cout << pHeaderCopy->row << endl;

	//clear memory
	while (pHeader != 0)
	{
		pop(pHeader);
	}
}
void renumber(FileRows *&pHeader)
{
	/*
	FileRows *pHeaderCopy = pHeader;
	FileRows *pLast = pHeader;
	int counter = 1;
	*/
	/*
	while (pLast->addr != 0)
	{
		pLast = pLast->addr;
		++counter;
	}
	*/
	/*
	while (NULL != pHeaderCopy)
	{
		char *str = new char[strlen(pHeaderCopy->row) + 3];
		_itoa_s(counter, str, strlen(str), 10);
		str[1] = ':';
		str[2] = ' ';
		int length = strlen(str);
		for (int i = 3; i < length; ++i)
		{
			str[i] = (pHeaderCopy->row)[i - 3];
		}
		strcpy_s(pHeaderCopy->row, strlen(pHeaderCopy->row), str);
		pHeaderCopy = pHeaderCopy->addr;
		--counter;
	}
	*/

	FileRows *pHeaderCopy = pHeader, *pLast = pHeader;
	int counter = 0;
	
	while (NULL != pLast)
	{
		pLast = pLast->addr;
		++counter;
	}
	while (NULL != pHeaderCopy)
	{
		int rowLength = strlen(pHeaderCopy->row);
		char *str = new char[rowLength + 4];
		_itoa_s(counter, str, 2, 10);
		str[1] = ':';
		str[2] = ' ';
		for (int i = 3; i < rowLength + 3; ++i)
			str[i] = (pHeaderCopy->row)[i - 3];
		str[rowLength + 3] = '\0';
		delete[](pHeaderCopy->row);
		pHeaderCopy->row = new char[rowLength + 5];
		strcpy_s(pHeaderCopy->row, rowLength + 5, str);
		delete[]str;
		--counter;
		pHeaderCopy = pHeaderCopy->addr;
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
		if (F.eof())
			F.clear();

		F.seekg(allLinesSize, ios::beg);


		char *str = new char[lineSize];
		F.read(str, lineSize);
		str[lineSize - 1] = '\0';
		push(str, pHeader);
		allLinesSize += (lineSize + 1);
		
		delete str; 
	}
	F.close();

	return pHeader;
}