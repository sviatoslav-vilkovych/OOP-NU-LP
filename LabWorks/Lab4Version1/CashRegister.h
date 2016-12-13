#pragma once
#include "header.h"
#include "ticket.h"
class CashRegister {
	/* data */
	size_t number; //number of cashRegister
	// additional data
	size_t num_sold_tickets;
	size_t earned_money;
	int max_amount_of_money; // before cash collection
	size_t paper_remained;
	vector<ticket*> returned_tickets;
	vector<ticket*> sold_tickets;

	static size_t freeCashNum;
protected:
	ticket ticketRegister; // { number, Name of customer, place, price }
public:
	char* passenger; // passenger initials
	// additional data
	short int work_hours[2][7];
	vector<char*> avaliable_flights;


	/* methods */
	CashRegister();
	CashRegister(const int&, const size_t&, short int **, vector<char *>); // { max_amount_of_money, paper_remained, work_hours, avaliable_fligt}
	CashRegister(const CashRegister &);
	~CashRegister();
	// output
	void printClass();
	void printClassToFile();
	// input
	int initClass();
	int initClassFromFile(char *fileName = NULL);
	//for updating prog
	void sold(char* flightLocation, size_t money, char* passengerName = "passenger", size_t amount_of_tickets = 1);
	bool sold() { return (!strcmp(passenger, "empty")) ? 1 : 0; };
	
	int set_passenger(char *passengernName = NULL);
	size_t get_number() { return number; };
	// overloaded functions
	bool CashRegister::operator==(CashRegister ob2) { return (number == ob2.number); };
	bool CashRegister::operator<(CashRegister ob2) { return (number < ob2.number); };
	bool CashRegister::operator>(CashRegister ob2) { return (number > ob2.number); };
	bool CashRegister::operator>=(CashRegister ob2) { return (number >= ob2.number); };
	bool CashRegister::operator<=(CashRegister ob2) { return (number <= ob2.number); };


	friend fstream &operator>>(fstream &stream, CashRegister &obj);
	friend ostream &operator<<(ostream &stream, CashRegister &obj);
	friend istream &operator>>(istream &stream, CashRegister &obj);

};
