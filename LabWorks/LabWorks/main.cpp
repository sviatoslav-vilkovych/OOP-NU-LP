#include <stdio.h>
#include <cstdlib>
#include <string.h>
#include <stdlib.h>

struct FileRows {
	char row[255];
	FileRows *addr;
} *pHeader, *pLast, *pLastHelper;
inline void menu(FILE(*&F));
void push()
{

}
void pop()
{

}
void renumber()
{
	FileRows *pHeaderHelper = pHeader;
	int counter = 1;
	while (pHeaderHelper != pLastHelper)
	{
		while (pLast->addr != pHeaderHelper)
		{
			pLast = pLast->addr;
		}

		char *str = (char*)malloc(sizeof((pLast->addr)->row));
		itoa(counter,str,10);
		strcat(str, ": ");
		strcat(str,((pLast->addr)->row));
		strcpy(((pLast->addr)->row), str);
		free(str);

		counter = counter + 1;
		pHeaderHelper = pLast;
		pLast = pLastHelper;
	}
	char *str = (char*)malloc(sizeof(pLast->row));
	itoa(counter, str, 10);
	strcat(str, ": ");
	strcat(str, (pLast->row));
	strcpy((pLast->row), str);
	free(str);

}
void loadFileToStack(FILE *F)
{
	pHeader = (FileRows*)malloc(sizeof FileRows);
	fgets(pHeader->row, 255, F);
	pHeader->addr = NULL;
	pLastHelper = pLast = pHeader;
	while (!feof(F))
	{
		pLast = (FileRows*)malloc(sizeof FileRows);
		fgets(pLast->row, 255, F);
		pLast->addr = pLastHelper;
		pLastHelper = pLast;
	}
}
void purge(const bool &outputWay, FILE *(&F))
{
	if (outputWay) 
	{// linear output
		while (pLast->addr != 0)
		{
			while (pLast->addr != pHeader)
			{
				pLast = pLast->addr;
			}
			printf("%s", (pLast->addr)->row);
			free(pHeader);
			pLast->addr = 0;
			pHeader = pLast;
			pLast = pLastHelper;
		}
		printf("%s", pLast->row);
	}
	else
	{//inverse output
		printf("%s\n", pLast->row);
		pLastHelper = pLast;
		pLast = pLast->addr;
		free(pLastHelper);
		while (pLast != NULL)
		{
			printf("%s", pLast->row);
			pLastHelper = pLast;
			pLast = pLast->addr;
			free(pLastHelper);
		}
	}
	printf("\n\n");
}
inline void task1(FILE *F)
{
	printf("%s\n", "__________________________________________________________");

	char buff[255];
	while (!feof(F))
	{
		fgets(buff, 255, F);
		printf("%s", buff);
	}
	printf("\n\n");

	printf("%s\n", "Press enter to back to main menu");
	getchar();
	getchar();
	system("cls");

}
inline void task2(FILE *F)
{
	printf("%s", "How do you wanna output data? For linear write \"1\". For inverse write \"0\". ");

	int outputWay;
	scanf("%i", &outputWay);
	printf("%s\n", "__________________________________________________________");
	purge(outputWay, F);
}
inline void subMenu(FILE *F)
{
	loadFileToStack(F);
	int choose;
	do {
		printf("%s\n", "Choose action: ");
		printf("%s\n", "1. Push element to stack. ");
		printf("%s\n", "2. Renumber all data in stack.");
		printf("%s\n", "3. Pop element from stack.");
		printf("%s\n", "4. Output stack and purge data.");
		printf("%s\n", "0. Back to main menu.");
		scanf("%i", &choose);

		system("cls");

		switch (choose)
		{
		case 0: return;
			break;
		case 1: push();
			break;
		case 2: renumber();
			break;
		case 3: pop();
			break;
		case 4: task2(F); return;
			break;
		default: printf("%s", "Please, press key from 0 to 4.");
			break;
		}
	} while (choose != 0);
}
inline void menu(FILE (*&F))
{
	int choose;
	do {
		fseek(F, 0, SEEK_SET);
		printf("%s\n", "Make your choice: ");
		printf("%s\n", "1. Read data from file and output it.");
		printf("%s\n", "2. Read data from file and put it into stack.");
		printf("%s\n", "0. Quit.");
		scanf("%i", &choose);

		system("cls");

		switch (choose)
		{
		case 0: exit(1);
			break;
		case 1: task1(F);
			break;
		case 2: subMenu(F);
			break;
		default: printf("%s", "Please, press key from 0 to 2. ");
			break;
		}
	} while (choose != 0);
}
void main()
{
	FILE *F;
	F = fopen("test.txt", "rb");

	if (NULL == F) {
		printf("%s", "Can't open the file.");
		return;
	}

	menu(F);
	
	fclose(F);
}