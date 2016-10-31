/* 
CLASS "CASH_REGISTER"
Lab work #3.

*/
#include "header.h"
#include "CashRegister.h"

size_t CashRegister::freeCashNum = 10000;

int main() {
	
	CashRegister obj, obj2;
	CashRegister *p_obj = NULL;

	obj.initClass();
	obj.printClassToFile();
	obj2.printClassToFile();
	obj2.initClassFromFile();
	
	return 0;
}