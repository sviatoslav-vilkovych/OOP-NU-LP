#include "functions.h"

int main()
{	
	TCHAR Buffer[MAX_PATH]; // path
	DWORD dwRet; // error checker
	dwRet = GetCurrentDirectory(MAX_PATH, Buffer);  // gets folder from which program runs
	wcscat_s(Buffer, L"\\Resource Files\\*");
	WIN32_FIND_DATA FindFileData; // file struct
	HANDLE hFind;

	hFind = FindFirstFile(Buffer, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE)
	{
		cout << "Invalid File Handle. GetLastError reports " << GetLastError() << endl;
		return (0);
	}
	// <!> BEGIN SKIP "." and "..".
	FindNextFile(hFind, &FindFileData);
	FindNextFile(hFind, &FindFileData);
	// <!> END SKIP
	int count = 1;
	cout << "Choice file which you wanna open:\n ";
	do {
			wcout << "\t" << count << ". " << FindFileData.cFileName << endl;
			++count;
	} while (FindNextFile(hFind, &FindFileData) != NULL);

	dwRet = GetLastError();
	FindClose(hFind);	

	char str[200] = "Resource Files\\";
	char str2[100];
	cout << "Please write which file you wanna open: ";
	cin.getline(str2,100);
	strcat_s(str, 200, str2);
	FileRows *pHeader = NULL;
	pHeader = loadFileToStack(str);
	renumber(pHeader);
	purge(pHeader);


}