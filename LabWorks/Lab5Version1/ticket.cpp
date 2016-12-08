#include "header.h"
#include "ticket.h"
ticket::ticket(size_t num, char* passengerName, char* flightLocation, size_t money)
{
	set_pass(passengerName);
	set_route(flightLocation);
	set_num(num);
	set_price(money);
}
ticket::ticket(const ticket&obj)
{
	int length = strlen(obj.passenger);
	passenger = new char[length + 1];
	for (int i = 0; i < length; ++i)
		passenger[i] = obj.passenger[i];
	passenger[length] = '\0';

	length = strlen(obj.route);
	route = new char[length + 1];
	for (int i = 0; i < length; ++i)
		route[i] = obj.route[i];
	route[length] = '\0';
}

void ticket::set_pass(char *passengerName)
{
	int length = strlen(passengerName);
	passenger = new char[length + 1];
	for (int i = 0; i < length; ++i)
		passenger[i] = passengerName[i];
	passenger[length] = '\0';
}
void ticket::set_route(char *flightLocation)
{
	int length = strlen(flightLocation);
	route = new char[length + 1];
	for (int i = 0; i < length; ++i)
		route[i] = flightLocation[i];
	route[length] = '\0';
}