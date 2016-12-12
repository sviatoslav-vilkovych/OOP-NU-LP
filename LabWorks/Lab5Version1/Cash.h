#pragma once
#include "header.h"
class Cash {
protected:
	size_t number; //number of cashRegister
	size_t num_sold_tickets;
	size_t earned_money;
	int max_amount_of_money; // before cash collection
	size_t paper_remained;
	CashType machine;
public:

	Cash();
	~Cash();
	virtual bool sold() = 0;
	virtual void printClass() = 0;
	virtual bool operator<(Cash& ob2) { return (number < ob2.number); };
};

