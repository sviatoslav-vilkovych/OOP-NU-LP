#include "CashRegister.h"


/* methods */
CashRegister::CashRegister()
{
	// number of cashregister
	number = freeCashNum;
	++freeCashNum;

	num_sold_tickets = 0;
	earned_money = 0;
	max_amount_of_money = 10000;
	left_paper = 1000;

	passenger = new char[6];
	passenger = "empty\0";
	
	// from M to F = 8-18; Sat,Sun = holiday;
	for (int j = 0; j < 5; ++j)
	{
		work_hours[0][j] = 8;
		work_hours[1][j] = 18;
	}
	work_hours[0][5] = -1;
	work_hours[1][5] = -1;
	work_hours[0][6] = -1;
	work_hours[1][6] = -1;
}
CashRegister::CashRegister(int, size_t, size_t **, map<char*, int>)
{

}
CashRegister::CashRegister(const CashRegister &obj)
{
}
CashRegister::~CashRegister() 
{
	delete this
};
// output
void CashRegister::printClass()
{
}
void CashRegister::printClassToFile()
{
}
// input
void CashRegister::InitClass()
{
}
void CashRegister::InitClassFromFile()
{
}
//for updating prog
void CashRegister::sold(char* flightLocation, char* passangerName, size_t amount_of_tickets)
{
}
