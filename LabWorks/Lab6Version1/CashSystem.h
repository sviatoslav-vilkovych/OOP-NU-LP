#pragma once
#include "Cash.h"
#include "ticket.h"
class CashSystem : public Cash {
protected:
	static size_t freeCashNum;

	vector<ticket*> returned_tickets;
	vector<ticket*> sold_tickets;
	ticket ticketRegister; // { number, Name of customer, place, price }

public:
	char* passenger; // passenger initials

	CashSystem();
	~CashSystem();
	// overloaded functions
	virtual bool sold() { return (!strcmp(passenger, "empty")) ? 1 : 0; };
	virtual void printClass();
};

