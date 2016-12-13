/* 
CLASS "CASH_REGISTER"
Lab work #3.

*/
#include "header.h"

size_t CashRegister::freeCashNum = 10000;

int main() {
	
	CashRegister obj, obj2;
	CashRegister *p_obj = NULL;
	/// IT IS LAB4
	
	// OUTPUT
	char cashRegisterOut[10];
	_itoa_s(obj.get_number(), cashRegisterOut, 10, 10);
	char strOut[40];
	strcpy_s(strOut, "CashRegister#");
	strcat_s(strOut, cashRegisterOut);
	strcat_s(strOut, ".txt");
	fstream output(strOut, ios::out | ios::trunc);
	// PROG
	cin >> obj;
	if(obj.sold())
		obj.sold("Paris", 300 ,"Janna Dark");
	if (obj.sold())
		obj.sold("Ivano-Frankivsk", 100, "Yoda");
	output << obj;
	cout << obj;
	output.close();
	// INPUT
	char cashRegisterIn[10];
	_itoa_s(obj.get_number(), cashRegisterIn, 10, 10);
	char fileName[40];
	cout << "Write the name of file to init obj2 (empty line for standart fileName):";
	cin.getline(fileName, 39);
	char strIn[40];
	if (NULL == fileName)
	{
		strcpy_s(strIn, "CashRegister#");
		strcat_s(strIn, cashRegisterIn);
		strcat_s(strIn, ".txt");
	}
	else
		strcpy_s(strIn, fileName);
	fstream init(strIn, ios::in | ios::binary);
	if (!init)
	{
		cout << "Can not open file with \"" << strIn << "\" name.\n";
	}

	init >> obj2;
	if (obj2.sold())
		obj2.sold("Berlin", 320, "Gargn Bernos");
	

	CashRegister objects[10];
	// swap
	swap(objects[2], objects[7]);
	swap(objects[1], objects[4]);

	// end swap
	bool isSorted = false;
	while (!isSorted)
	{
		isSorted = true;
		for (int i = 0; i < 8; ++i)
		{
			if (objects[i] > objects[i + 1])
			{
				swap(objects[i], objects[i + 1]);
				isSorted = false;
			}
		}
	}

	init.close();
	

	return 0;
}