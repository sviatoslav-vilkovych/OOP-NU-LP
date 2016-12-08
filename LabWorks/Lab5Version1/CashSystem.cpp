#include "CashSystem.h"



CashSystem::CashSystem()
{
	// number of cashregister
	number = freeCashNum;
	++freeCashNum;
}


CashSystem::~CashSystem()
{
}

void CashSystem::printClass()
{
	cout << "Cash #" << number << endl;
	cout << "First initialization:\n";
	cout << "Num of solded tickets: " << num_sold_tickets << endl;
	cout << "Num of earned money: " << earned_money << endl;
	cout << "Num of max amount of money: " << max_amount_of_money << endl;
	cout << "Num of paper remained: " << paper_remained << endl;
	cout << "________________________________\n";
}