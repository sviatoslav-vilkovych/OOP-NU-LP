#pragma once
#include "header.h"

class CashRegister {
	/* data */
	size_t number; //number of cashRegister
	// additional data
	size_t num_sold_tickets;
	size_t earned_money;
	int max_amount_of_money; // before cash collection
	size_t left_paper;
	map<char*, size_t> returned_tickets;

	static size_t freeCashNum;
protected:
	ticket ticketRegister; // { number, Name of customer, place }
public:
	char* passenger; // passenger initials
	// additional data
	short int work_hours[2][7];
	map <int, char*> avaliable_flights; 

	/* methods */
	CashRegister();
	CashRegister(int, size_t, size_t **, map<char*, int>); // { max_amount_of_money, left_paper, work_hours, avaliable_fligt}
	CashRegister(const CashRegister &);
	~CashRegister();
	// output
	void printClass();
	void printClassToFile();
	// input
	void InitClass();
	void InitClassFromFile();
	//for updating prog
	void sold(char* flightLocation, char* passangerName = "passenger", size_t amount_of_tickets = 1);
	bool sold() { return (passenger == "empty") ? 1 : 0; };
};

