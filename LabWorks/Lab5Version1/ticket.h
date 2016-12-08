#pragma once
#include "header.h"

class ticket {
	size_t number; // ticket number
	char *passenger;
	char *route;
	size_t price;
public:
	ticket() { passenger = 0; route = 0; price = 0; number = 0; };
	ticket(size_t, char*, char*, size_t);
	ticket(const ticket&);
	~ticket() { delete[]passenger; delete[] route; };
	size_t get_num() { return number; };
	size_t get_price() { return price; };
	char *get_pass() { return passenger; };
	char *get_route() { return route; };

	void set_num(size_t num) { number = num; };
	void set_price(size_t money) { price = money; };
	void set_pass(char*);
	void set_route(char*);

};