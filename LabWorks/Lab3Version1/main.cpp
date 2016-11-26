/* 
CLASS "CASH_REGISTER"
Lab work #3.

*/
#include "header.h"

size_t CashRegister::freeCashNum = 10000;

int main() {
	
	CashRegister obj, obj2;
	CashRegister *p_obj = NULL;

	obj.initClass();

	if(obj.sold())
		obj.sold("Paris", 300 ,"Janna Dark");
	if (obj.sold())
		obj.sold("Ivano-Frankivsk", 100, "Yoda");
	obj.printClassToFile();
	obj.printClass();

	obj2.initClassFromFile("CashRegister#10000.txt");
	if (obj2.sold())
		obj2.sold("Berlin", 320, "Gargn Bernos");
	obj2.printClassToFile();

	return 0;
}