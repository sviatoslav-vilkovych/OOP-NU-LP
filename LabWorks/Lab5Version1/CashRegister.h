#pragma once
#include "header.h"
#include "CashSystem.h"
class CashRegister: public CashSystem {

public:
	// additional data
	short int work_hours[2][7];
	vector<char*> avaliable_flights;

	
	/* methods */
	CashRegister();
	CashRegister(const int&, const size_t&, short int **, vector<char *>); // { max_amount_of_money, paper_remained, work_hours, avaliable_fligt}
	CashRegister(const CashRegister &);
	~CashRegister();
	// output
	virtual void printClass();
	void printClassToFile();
	// input
	int initClass();
	int initClassFromFile(char *fileName = NULL);
	//for updating prog
	size_t get_number() { return number; };
	virtual void sold(char* flightLocation, size_t money, char* passengerName = "passenger", size_t amount_of_tickets = 1);
	virtual bool sold() { return (!strcmp(passenger, "empty")) ? 1 : 0; };
	
	int set_passenger(char *passengernName = NULL);

	virtual bool operator==(CashRegister& ob2) { return (number == ob2.number); };
	
	virtual bool operator>(CashRegister& ob2) { return (number > ob2.number); };
	virtual bool operator>=(CashRegister& ob2) { return (number >= ob2.number); };
	virtual bool operator<=(CashRegister& ob2) { return (number <= ob2.number); };

	friend ifstream &operator >> (ifstream &stream, CashRegister &obj);
	friend ostream &operator<<(ostream &stream, CashRegister &obj);
	friend istream &operator>>(istream &stream, CashRegister &obj);
	
};
