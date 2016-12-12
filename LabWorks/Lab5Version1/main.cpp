/* 
CLASS "CASH_REGISTER"
Lab work #3.

*/
#include "header.h"
#include "CashRegister.h"
#include "pbDeliveredFromCashRegister.h"
#include "prDeliveredFromCashRegister.h"
#include "ptDelivedFromCashRegister.h"
size_t CashSystem::freeCashNum = 10000;

int main() {
	
	CashRegister obj,obj2;
	if (obj < obj2)
	{
		cout << "#2.2 : obj<obj2";
	}
	/// IT IS LAB5
	/// 1.3.4, 1.3.2, 1.3.1
	//prDeliveredFromCashRegister OBJ;
	//OBJ.initClass();
	/// 1.3.3
	//pbDeliveredFromCashRegister OBJ;
	//OBJ.initClass();
	//OBJ.CashSystem::printClass(); // from CashSystem
	//OBJ.printClass(); // from CashRegister

	// OUTPUT
	char cashRegisterOut[10];
	_itoa_s(obj.get_number(), cashRegisterOut, 10, 10);
	char strOut[40];
	strcpy_s(strOut, "CashRegister#");
	strcat_s(strOut, cashRegisterOut);
	strcat_s(strOut, ".txt");
	ofstream output(strOut, ios::out | ios::trunc);
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
	ifstream init(strIn, ios::in | ios::binary);
	
	init >> obj2;
	if (obj2.sold())
		obj2.sold("Berlin", 320, "Gargn Bernos");
	

	Cash *pObj;
	CashSystem OBJ;
	pObj = &obj;
	pObj->printClass();
	pObj = &OBJ;
	pObj->printClass();

	
	

	/// IT IS LAB3
	//obj.initClass();
	//if(obj.sold())
	//	obj.sold("Paris", 300 ,"Janna Dark");
	//if (obj.sold())
	//	obj.sold("Ivano-Frankivsk", 100, "Yoda");
	//obj.printClassToFile();
	//obj.printClass();

	//obj2.initClassFromFile("CashRegister#10000.txt");
	//if (obj2.sold())
	//	obj2.sold("Berlin", 320, "Gargn Bernos");
	//obj2.printClassToFile();
	init.close();
	

	return 0;
}