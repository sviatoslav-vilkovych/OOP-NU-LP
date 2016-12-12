#include "Cash.h"



Cash::Cash()
{
	num_sold_tickets = 0;
	earned_money = 0;
	max_amount_of_money = 10000;
	paper_remained = 1000;
	machine = MarketMachine;
}


Cash::~Cash()
{
}
