#include "header.h"

/* methods */
CashRegister::CashRegister()
{
	// number of cashregister
	number = freeCashNum;
	++freeCashNum;

	num_sold_tickets = 0;
	earned_money = 0;
	max_amount_of_money = 10000;
	paper_remained = 1000;

	set_passenger("empty");
	
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

	/* NO AVALIABLE FLIGHTS ???*/
}
CashRegister::CashRegister(const int &max_amount_of_moneyL,const size_t &left_paperL, short int **work_hoursL, vector<char *> avaliable_flightsL)
{
	number = freeCashNum;
	++freeCashNum;

	num_sold_tickets = 0;
	earned_money = 0;
	max_amount_of_money = max_amount_of_moneyL;
	paper_remained = left_paperL;

	passenger = new char[6];
	passenger = "empty\0";

	for (int j = 0; j < 7; ++j)
	{
		work_hours[0][j] = work_hoursL[0][j];
		work_hours[1][j] = work_hoursL[1][j];
	}

	avaliable_flights = avaliable_flightsL;
}
CashRegister::CashRegister(const CashRegister &obj)
{
	int length = strlen(obj.passenger);
	passenger = new char[length + 1];
	for (int i = 0; i < length; ++i)
		passenger[i] = obj.passenger[i];
	passenger[length] = '\0';
}
CashRegister::~CashRegister() 
{
	returned_tickets.clear();
	sold_tickets.clear();
	avaliable_flights.clear();
}
// output
void CashRegister::printClass() 
{
	cout.clear();
	cout << "__________________________________________________________________________\n";
	cout << "Cash Register #" << number << " :\n";
	
	/* WORK HOURS */
	cout << "Work hours of this cash:\n\t";
	char *nameOfDays[7] = { {"Monday: "}, {"Tuesday: "}, {"Wednesday: "} , {"Thursday: "} , {"Friday: "} , {"Saturday: "} , {"Sunday: "} };
	cout.setf(ios::left);
	for (int i = 0; i < 7; ++i)
	{
		cout << setw(12) << nameOfDays[i];
		if (work_hours[0][i]<0 || work_hours[1][i] <0)
			cout << ("-> Weekend <-;\n\t");
		else
			cout << " " << work_hours[0][i] << ":00 to " << work_hours[1][i] << ":00;\n\t";
	}
	/* AVALIABLE FLIGHTS */
	cout << "\nAvaliable flights from the cash:\n\t";
	vector<char*>::iterator flights;
	flights = avaliable_flights.begin();
	if (flights == avaliable_flights.end())
		cout << "No avaliable flights registred.\n";
	else
		while (flights != avaliable_flights.end())
		{
			cout << "> " << *flights << "\n\t";
			++flights;
		}

	/* CAUTION! PRIVATE INFORMATION */
	cout << "\nAlready sold " << num_sold_tickets << " tickets;\n";
	cout << "Earn " << earned_money << "$ (of maximum " << max_amount_of_money << ");\n";
	cout << "Paper remained " << paper_remained << ";\n";
	
	cout << "\nList of returned tickets:\n\t";
	vector<ticket*>::iterator tickets;
	tickets = returned_tickets.begin();
	if (tickets == returned_tickets.end())
		cout << "No returned tickets.\n";
	else
		while (tickets != returned_tickets.end())
		{	
			cout	<< "#" << (*tickets)->get_num() 
					<< " | Name of passenger: " << (*tickets)->get_pass() 
					<< "\n\t\t| Route: " << (*tickets)->get_route() 
					<< "\n\t\t| Price: " << (*tickets)->get_price() << "\n\t";
			++tickets;
		}
	cout << "\nSold Tickets:\n\t";
	tickets = sold_tickets.begin();
	if (tickets == sold_tickets.end())
		cout << "No sold tickets.\n";
	else
		while (tickets != sold_tickets.end())
		{
			cout	<< "#" << (*tickets)->get_num()
					<< " | Name of passenger: " << (*tickets)->get_pass()
					<< "\n\t\t| Route: " << (*tickets)->get_route()
					<< "\n\t\t| Price: " << (*tickets)->get_price() << "\n\t";
			++tickets;
		}
	cout << "\n__________________________________________________________________________\n";
} 
void CashRegister::printClassToFile()
{
	char cashRegister[10];
	_itoa_s(number, cashRegister, 10, 10);
	
	/* strcat_s somewhy don't work with dynamic memory. */

	char str[40];
	strcpy_s(str, "CashRegister#");
	strcat_s(str, cashRegister);
	strcat_s(str, ".txt");
	
	fstream output(str, ios::out | ios::trunc);

	output << "Cash Register #" << number << " :\n";

	/* WORK HOURS */
	output << "Work hours of this cash:\n\t";
	char *nameOfDays[7] = { { "Monday: " },{ "Tuesday: " },{ "Wednesday: " } ,{ "Thursday: " } ,{ "Friday: " } ,{ "Saturday: " } ,{ "Sunday: " } };
	output.setf(ios::left);
	for (int i = 0; i < 7; ++i)
	{
		output << setw(12) << nameOfDays[i];
		if (work_hours[0][i]<0 || work_hours[1][i] <0)
			output << ("-> Weekend <-;\n\t");
		else
			output << " " << work_hours[0][i] << ":00 to " << work_hours[1][i] << ":00;\n\t";
	}
	/* AVALIABLE FLIGHTS */
	output << "\nAvaliable flights from the cash:\n\t";
	vector<char*>::iterator flights;
	flights = avaliable_flights.begin();
	if (flights == avaliable_flights.end())
		output << "!No avaliable flights registred!\n\t";
	else
	{
		while (flights != avaliable_flights.end())
		{
			output << "> " << *flights << "\n\t";
			++flights;
		}
		output << "!No more avaliable flights registred!\n\t";
	}
	/* CAUTION! PRIVATE INFORMATION */
	output << "\nAlready sold " << num_sold_tickets << " tickets;\n";
	output << "Earn " << earned_money << "$ (of maximum " << max_amount_of_money << ");\n";
	output << "Paper remained " << paper_remained << ";\n";

	output << "\nList of returned tickets:\n\t";
	vector<ticket*>::iterator tickets;
	tickets = returned_tickets.begin();
	if (tickets == returned_tickets.end())
		output << "!No returned tickets!\n";
	else
	{
		while (tickets != returned_tickets.end())
		{
			output	<< "#" << (*tickets)->get_num() 
					<< " | Name of passenger: " << (*tickets)->get_pass()
					<< "\n\t\t| Route: " << (*tickets)->get_route() 
					<< "\n\t\t| Price: " << (*tickets)->get_price() << "\n\t";
			++tickets;
		}
		output << "!No more returned tickets!\n";
	}
	output << "\nSold Tickets:\n\t";
	tickets = sold_tickets.begin();
	if (tickets == sold_tickets.end())
		output << "!No sold tickets!\n";
	else
	{
		while (tickets != sold_tickets.end())
		{
			output	<< "#" << (*tickets)->get_num() 
					<< " | Name of passenger: " << (*tickets)->get_pass() 
					<< "\n\t\t| Route: " << (*tickets)->get_route() 
					<< "\n\t\t| Price: " << (*tickets)->get_price() <<"\n\t";
			++tickets;
		}
		output << "!No more solded tickets!\n";
	}

	cout << "\n<<< Information about CashRegister#" << number << " written to file. >>>\n";

	output.close();
}
// input
int CashRegister::initClass()
{
	cout.clear();
	cout << "__________________________________________________________________________\n";
	cout << "Please enter max amount money for cash register before cash collection: ";
	cin >> max_amount_of_money;
	if (max_amount_of_money < 0)
		max_amount_of_money = -max_amount_of_money;
	cout << "Please enter amount of paper: ";
	int paper_remained_prot;
	cin >> paper_remained_prot;
	paper_remained = (paper_remained_prot < 0) ? -paper_remained_prot : paper_remained_prot;

	cout << "Please enter work hours of this cash ('-1' for weekend):\n\t";
	char nameOfDays[7][13] = { { "Monday: " },{ "Tuesday: " },{ "Wednesday: " } ,{ "Thursday: " } ,{ "Friday: " } ,{ "Saturday: " } ,{ "Sunday: " } };

	for (int i = 0; i < 7; ++i)
	{
		cout << nameOfDays[i] << "\n\t";
		cout << "| Work starts: ";
		cin >> work_hours[0][i];
		cout << "\t| Work ends: ";
		cin >> work_hours[1][i];
		cout << "\t";
		
	}

	cout << "\nPlease enter avaliable flights (\"q\" for quit):\n\t";
	cin.clear();
	cin.get();
	while (true) {
		
		char *flight = new char[30];
		cin.getline(flight, 30);
		if ('\0' == flight[0])
			break;
		cout << "\t";
		avaliable_flights.push_back(flight);
	}
	cout.clear();
	cout << "__________________________________________________________________________\n";
	return 0;
}
int CashRegister::initClassFromFile(char *fileName)
{
	char cashRegister[10];
	_itoa_s(number, cashRegister, 10, 10);

	/* strcat_s somewhy don't work with dynamic memory. */
	
	char str[40];
	if (NULL == fileName)
	{
		strcpy_s(str, "CashRegister#");
		strcat_s(str, cashRegister);
		strcat_s(str, ".txt");
	}
	else
		strcpy_s(str, fileName);

	fstream init(str, ios::in | ios::binary);
	if (!init) {
		cout << "Can not open " << str << " file.\n";
		return 1;
	}

	char ch;
	while ((ch = init.get()) != 9); // horizontal tab = 9
	init.seekg(12, ios::cur);
	/* WORK HOURS */
	for (int i = 0; i < 7; ++i)
	{
		if (' ' == (ch = init.get()))
		{
			init >> work_hours[0][i];
			//init.read((char*)&(work_hours[0][i]), sizeof work_hours[0][i]);
			init.seekg(7, ios::cur);
			init >> work_hours[1][i];
			//init.read((char*)&(work_hours[1][i]), sizeof work_hours[1][i]);
		}
		else
			work_hours[0][i] = work_hours[1][i] = -1;

		while ((ch = init.get()) != 9); // horizontal tab = 9
		if (6 != i)
			init.seekg(12, ios::cur);
	}

	while (ch = init.get() != ':'); // 
	init.seekg(3, ios::cur);
	// Aval flights.
	while ((ch = init.get()) != '!')
	{
		init.seekg(1, ios::cur);
		char *aval = new char[30];
		init.getline(aval, 30, '\r');
		avaliable_flights.push_back(aval);
		init.seekg(2, ios::cur); 
	}
	// Sold tickets
	init.seekg(54, ios::cur);
	init >> num_sold_tickets;
	// Earn $$$
	init.seekg(15, ios::cur);
	init >> earned_money;
	init.seekg(14, ios::cur);
	init >> max_amount_of_money;
	// Paper remained
	init.seekg(18, ios::cur);
	init >> paper_remained;
	
	// List of returned tickets
	while ((ch = init.get()) != ':');
	init.seekg(3, ios::cur);
	while ((ch = init.get()) != '!')
	{
		size_t tick = 0, money = 0;
		int how_much_go_back = 0;
		char *passengerName = NULL, *flightLocation = NULL;

		init >> tick;
		/* PASSENGER NAME */
		init.seekg(22, ios::cur);
		while ((ch = init.get()) != '\r')
			++how_much_go_back;
		init.seekg(-1 * (how_much_go_back + 1), ios::cur);
		passengerName = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			passengerName[i] = init.get();
		passengerName[how_much_go_back] = '\0';
		how_much_go_back = 0;
		/* FLIGHT LOCATION */
		init.seekg(13, ios::cur);
		while ((ch = init.get()) != '\r')
			++how_much_go_back;
		init.seekg(-1 * (how_much_go_back + 1), ios::cur);
		flightLocation = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			flightLocation[i] = init.get();
		flightLocation[how_much_go_back] = '\0';
		/* PRICE */
		init.seekg(13, ios::cur);
		init >> money;

		ticket *returned_ticket = new ticket(tick, passengerName, flightLocation, money);

		returned_tickets.push_back(returned_ticket);
		init.seekg(3, ios::cur);
	}

	// Sold Tickets list
	while ((ch = init.get()) != ':');
	init.seekg(3, ios::cur);
	while ((ch = init.get()) != '!')
	{
		size_t tick = 0, money = 0;
		int how_much_go_back = 0;
		char *passengerName = NULL, *flightLocation = NULL;

		init >> tick;
		/* PASSENGER NAME */
		init.seekg(22, ios::cur);
		while ((ch = init.get()) != '\r')
			++how_much_go_back;
		init.seekg(-1 * (how_much_go_back+1), ios::cur);
		passengerName = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			passengerName[i] = init.get();
		passengerName[how_much_go_back] = '\0';
		how_much_go_back = 0;
		/* FLIGHT LOCATION */
		init.seekg(13, ios::cur);
		while ((ch = init.get()) != '\r')
			++how_much_go_back;
		init.seekg(-1 * (how_much_go_back+1), ios::cur);
		flightLocation = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			flightLocation[i] = init.get();
		flightLocation[how_much_go_back] = '\0';
		/* PRICE */
		init.seekg(13, ios::cur);
		init >> money;

		ticket *solding_ticket = new ticket(tick, passengerName, flightLocation, money);

		sold_tickets.push_back(solding_ticket);
		init.seekg(3, ios::cur);
	}
	init.close();
	
	cout << "\n<<< Information about CashRegister#" << number << " initialized from file. >>>\n";

	return 1;
}
//for updating prog
void CashRegister::sold(char* flightLocation, size_t money, char* passengerName, size_t amount_of_tickets)
{
	set_passenger();
	set_passenger(passengerName);
	/* FIND IN RETURNED TICKETS */
	bool isInReturned = false;
	vector<ticket*>::iterator r_ticket = returned_tickets.begin();
	while (r_ticket != returned_tickets.end())
	{
		if (!strcmp((*r_ticket)->get_route(), flightLocation))
		{
			isInReturned = true;
			break;
		}
		++r_ticket;
	}
	/* SHOULD FIND IN MAP flightLocation */
	bool isFlightPossible = false; 
	vector<char*>::iterator flights = avaliable_flights.begin();
	while (flights != avaliable_flights.end())
	{
		if (!strcmp(*flights, flightLocation))
		{
			isFlightPossible = true;
			break;
		}
		++flights;
	}

	bool isPaperEnough = (amount_of_tickets <= paper_remained) ? true : false;

	// price also
	bool isMoney = ((max_amount_of_money - (money*amount_of_tickets+earned_money)) > 0) ? true: false;

	if (isMoney && isFlightPossible && isPaperEnough)
	{
		if (isInReturned)
		{
			size_t ticket_num = (*r_ticket)->get_num();
			earned_money += money*amount_of_tickets;
			num_sold_tickets += amount_of_tickets;
			for (size_t i = 0; i < amount_of_tickets; ++i)
			{
				ticket *solding_ticket = new ticket(ticket_num, passengerName, flightLocation, money);

				sold_tickets.push_back(solding_ticket);
			}
		}
		else
		{
			earned_money += money*amount_of_tickets;
			paper_remained -= amount_of_tickets;
			num_sold_tickets += amount_of_tickets;
			for (size_t i = 0; i < amount_of_tickets; ++i)
			{
				ticket *solding_ticket = new ticket(rand() % 9000 + 1000, passengerName, flightLocation, money);

				sold_tickets.push_back(solding_ticket);
			}
		}
		cout << "\n<<< Sold ticket to " << passengerName << " was successful. >>>\n";
	}
	else 
		cout << "\n<<< Sold ticket to " << passengerName << " was unsuccessful. >>>\n";

	set_passenger("empty");
}
int CashRegister::set_passenger(char *passengerName)
{
	if (passengerName)
	{
		int length = strlen(passengerName);
		passenger = new char[length+1];
		for (int i = 0; i < length; ++i)
			passenger[i] = passengerName[i];
		passenger[length] = '\0';
	}
	else
	{
		delete[]passenger;
	}
	
	return 0;
}
// overloaded functions
ostream &operator<<(ostream &stream, CashRegister &obj)
{
	/*char cashRegister[10];
	_itoa_s(obj.number, cashRegister, 10, 10);*/

	/* strcat_s somewhy don't work with dynamic memory. */

	/*char str[40];
	strcpy_s(str, "CashRegister#");
	strcat_s(str, cashRegister);
	strcat_s(str, ".txt");*/

	// fstream output(str, ios::out | ios::trunc); TO MAIN

	stream << "Cash Register #" << obj.number << " :\n";

	/* WORK HOURS */
	stream << "Work hours of this cash:\n\t";
	char *nameOfDays[7] = { { "Monday: " },{ "Tuesday: " },{ "Wednesday: " } ,{ "Thursday: " } ,{ "Friday: " } ,{ "Saturday: " } ,{ "Sunday: " } };
	stream.setf(ios::left);
	for (int i = 0; i < 7; ++i)
	{
		stream << setw(12) << nameOfDays[i];
		if (obj.work_hours[0][i]<0 || obj.work_hours[1][i] <0)
			stream << ("-> Weekend <-;\n\t");
		else
			stream << " " << obj.work_hours[0][i] << ":00 to " << obj.work_hours[1][i] << ":00;\n\t";
	}
	/* AVALIABLE FLIGHTS */
	stream << "\nAvaliable flights from the cash:\n\t";
	vector<char*>::iterator flights;
	flights = obj.avaliable_flights.begin();
	if (flights == obj.avaliable_flights.end())
		stream << "!No avaliable flights registred!\n\t";
	else
	{
		while (flights != obj.avaliable_flights.end())
		{
			stream << "> " << *flights << "\n\t";
			++flights;
		}
		stream << "!No more avaliable flights registred!\n\t";
	}
	/* CAUTION! PRIVATE INFORMATION */
	stream << "\nAlready sold " << obj.num_sold_tickets << " tickets;\n";
	stream << "Earn " << obj.earned_money << "$ (of maximum " << obj.max_amount_of_money << ");\n";
	stream << "Paper remained " << obj.paper_remained << ";\n";

	stream << "\nList of returned tickets:\n\t";
	vector<ticket*>::iterator tickets;
	tickets = obj.returned_tickets.begin();
	if (tickets == obj.returned_tickets.end())
		stream << "!No returned tickets!\n";
	else
	{
		while (tickets != obj.returned_tickets.end())
		{
			stream << "#" << (*tickets)->get_num()
				<< " | Name of passenger: " << (*tickets)->get_pass()
				<< "\n\t\t| Route: " << (*tickets)->get_route()
				<< "\n\t\t| Price: " << (*tickets)->get_price() << "\n\t";
			++tickets;
		}
		stream << "!No more returned tickets!\n";
	}
	stream << "\nSold Tickets:\n\t";
	tickets = obj.sold_tickets.begin();
	if (tickets == obj.sold_tickets.end()) // would be nice to add iterator.
		stream << "!No sold tickets!\n";
	else
	{
		while (tickets != obj.sold_tickets.end())
		{
			stream << "#" << (*tickets)->get_num()
				<< " | Name of passenger: " << (*tickets)->get_pass()
				<< "\n\t\t| Route: " << (*tickets)->get_route()
				<< "\n\t\t| Price: " << (*tickets)->get_price() << "\n\t";
			++tickets;
		}
		stream << "!No more solded tickets!\n";
	}

	cout << "\n<<< Information about CashRegister#" << obj.number << " written to stream. >>>\n";

	// output.close() TO MAIN


	return stream;
}
istream &operator>>(istream &stream, CashRegister &obj)
{
	stream.clear();
	cout << "__________________________________________________________________________\n";
	cout << "Please enter max amount money for cash register before cash collection: ";
	stream >> obj.max_amount_of_money;
	if (obj.max_amount_of_money < 0)
		obj.max_amount_of_money = -obj.max_amount_of_money;
	cout << "Please enter amount of paper: ";
	int paper_remained_prot;
	stream >> paper_remained_prot;
	obj.paper_remained = (paper_remained_prot < 0) ? -paper_remained_prot : paper_remained_prot;

	cout << "Please enter work hours of this cash ('-1' for weekend):\n\t";
	char nameOfDays[7][13] = { { "Monday: " },{ "Tuesday: " },{ "Wednesday: " } ,{ "Thursday: " } ,{ "Friday: " } ,{ "Saturday: " } ,{ "Sunday: " } };

	for (int i = 0; i < 7; ++i)
	{
		cout << nameOfDays[i] << "\n\t";
		cout << "| Work starts: ";
		stream >> obj.work_hours[0][i];
		cout << "\t| Work ends: ";
		stream >> obj.work_hours[1][i];
		cout << "\t";

	}

	cout << "\nPlease enter avaliable flights (\"q\" for quit):\n\t";
	stream.clear();
	stream.get();
	while (true) {

		char *flight = new char[30];
		stream.getline(flight, 30);
		if ('\0' == flight[0])
			break;
		cout << "\t";
		obj.avaliable_flights.push_back(flight);
	}
	cout.clear();
	cout << "__________________________________________________________________________\n";
	return stream;
}
ifstream &operator >> (ifstream &stream, CashRegister &obj)
{
	//char cashRegister[10];
	//_itoa_s(number, cashRegister, 10, 10);

	///* strcat_s somewhy don't work with dynamic memory. */
	// TO MAINNNNNNNN
	//char str[40];
	//if (NULL == fileName)
	//{
	//	strcpy_s(str, "CashRegister#");
	//	strcat_s(str, cashRegister);
	//	strcat_s(str, ".txt");
	//}
	//else
	//	strcpy_s(str, fileName);
	
	// fstream init(str, ios::in | ios::binary); 
	/*if (!stream) {
		cout << "Can not open " << str << " file.\n";
		return 1;
	}*/
	if (!stream)
	{
		cout << "Can not open this file.\n";
		exit(1);
	}

	char ch;
	while ((ch = stream.get()) != 9); // horizontal tab = 9
	stream.seekg(12, ios::cur);
	/* WORK HOURS */
	for (int i = 0; i < 7; ++i)
	{
		if (' ' == (ch = stream.get()))
		{
			stream >> obj.work_hours[0][i];
			//init.read((char*)&(work_hours[0][i]), sizeof work_hours[0][i]);
			stream.seekg(7, ios::cur);
			stream >> obj.work_hours[1][i];
			//init.read((char*)&(work_hours[1][i]), sizeof work_hours[1][i]);
		}
		else
			obj.work_hours[0][i] = obj.work_hours[1][i] = -1;

		while ((ch = stream.get()) != 9); // horizontal tab = 9
		if (6 != i)
			stream.seekg(12, ios::cur);
	}

	while (ch = stream.get() != ':'); // 
	stream.seekg(3, ios::cur);
	// Aval flights.
	while ((ch = stream.get()) != '!')
	{
		stream.seekg(1, ios::cur);
		char *aval = new char[30];
		stream.getline(aval, 30, '\r');
		obj.avaliable_flights.push_back(aval);
		stream.seekg(2, ios::cur);
	}
	// Sold tickets
	stream.seekg(54, ios::cur);
	stream >> obj.num_sold_tickets;
	// Earn $$$
	stream.seekg(15, ios::cur);
	stream >> obj.earned_money;
	stream.seekg(14, ios::cur);
	stream >> obj.max_amount_of_money;
	// Paper remained
	stream.seekg(18, ios::cur);
	stream >> obj.paper_remained;

	// List of returned tickets
	while ((ch = stream.get()) != ':');
	stream.seekg(3, ios::cur);
	while ((ch = stream.get()) != '!')
	{
		size_t tick = 0, money = 0;
		int how_much_go_back = 0;
		char *passengerName = NULL, *flightLocation = NULL;

		stream >> tick;
		/* PASSENGER NAME */
		stream.seekg(22, ios::cur);
		while ((ch = stream.get()) != '\r')
			++how_much_go_back;
		stream.seekg(-1 * (how_much_go_back + 1), ios::cur);
		passengerName = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			passengerName[i] = stream.get();
		passengerName[how_much_go_back] = '\0';
		how_much_go_back = 0;
		/* FLIGHT LOCATION */
		stream.seekg(13, ios::cur);
		while ((ch = stream.get()) != '\r')
			++how_much_go_back;
		stream.seekg(-1 * (how_much_go_back + 1), ios::cur);
		flightLocation = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			flightLocation[i] = stream.get();
		flightLocation[how_much_go_back] = '\0';
		/* PRICE */
		stream.seekg(13, ios::cur);
		stream >> money;

		ticket *returned_ticket = new ticket(tick, passengerName, flightLocation, money);

		obj.returned_tickets.push_back(returned_ticket);
		stream.seekg(3, ios::cur);
	}

	// Sold Tickets list
	while ((ch = stream.get()) != ':');
	stream.seekg(3, ios::cur);
	while ((ch = stream.get()) != '!')
	{
		size_t tick = 0, money = 0;
		int how_much_go_back = 0;
		char *passengerName = NULL, *flightLocation = NULL;

		stream >> tick;
		/* PASSENGER NAME */
		stream.seekg(22, ios::cur);
		while ((ch = stream.get()) != '\r')
			++how_much_go_back;
		stream.seekg(-1 * (how_much_go_back + 1), ios::cur);
		passengerName = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			passengerName[i] = stream.get();
		passengerName[how_much_go_back] = '\0';
		how_much_go_back = 0;
		/* FLIGHT LOCATION */
		stream.seekg(13, ios::cur);
		while ((ch = stream.get()) != '\r')
			++how_much_go_back;
		stream.seekg(-1 * (how_much_go_back + 1), ios::cur);
		flightLocation = new char[how_much_go_back + 1];
		for (int i = 0; i < how_much_go_back; ++i)
			flightLocation[i] = stream.get();
		flightLocation[how_much_go_back] = '\0';
		/* PRICE */
		stream.seekg(13, ios::cur);
		stream >> money;

		ticket *solding_ticket = new ticket(tick, passengerName, flightLocation, money);

		obj.sold_tickets.push_back(solding_ticket);
		stream.seekg(3, ios::cur);
	}
	// stream.close(); TO MAIN

	cout << "\n<<< Information about CashRegister#" << obj.number << " initialized from file. >>>\n";

	return stream;

}