#include "CashRegister.h"
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

	passenger = new char[6];
	passenger = "empty\0";
	
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
CashRegister::CashRegister(const int &max_amount_of_moneyL,const size_t &left_paperL, short int **work_hoursL, map<int , char *> avaliable_flightsL)
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
	cout << "_____________________________________________";
	cout << "\nCash Register #" << number << " :\n";
	
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
	map<int, char*>::iterator flights;
	flights = avaliable_flights.begin();
	if (flights == avaliable_flights.end())
		cout << "No avaliable flights registred.\n";
	else
		while (flights != avaliable_flights.end())
		{
			cout << "> " << flights->second << "\n\t";
			++flights;
		}
	/* CAUTION! PRIVATE INFORMATION */
	cout << "\nAlready sold " << num_sold_tickets << " tickets;\n";
	cout << "Earn " << earned_money << "$ (of maximum " << max_amount_of_money << ");\n";
	cout << "Paper remained " << paper_remained << ";\n";
	
	cout << "\nList of returned tickets:\n\t";
	map<char*, ticket>::iterator tickets;
	tickets = returned_tickets.begin();
	if (tickets == returned_tickets.end())
		cout << "No returned tickets.\n";
	else
		while (tickets != returned_tickets.end())
		{	
			cout << "#" << (tickets->second).number << " | Name of passenger: " << (tickets->second).passenger << " | Route: " << (tickets->second).route << "\n\t";
			++tickets;
		}
	cout << "\nSold Tickets:\n\t";
	tickets = sold_tickets.begin();
	if (tickets == sold_tickets.end())
		cout << "No sold tickets.\n";
	else
		while (tickets != sold_tickets.end())
		{
			cout << "#" << (tickets->second).number << " | Name of passenger: " << (tickets->second).passenger << " | Route: " << (tickets->second).route << "\n\t";
			++tickets;
		}	
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
	
	fstream output(str, ios::out | ios::app);


	output << "_____________________________________________";
	output << "\nCash Register #" << number << " :\n";

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
	map<int, char*>::iterator flights;
	flights = avaliable_flights.begin();
	if (flights == avaliable_flights.end())
		output << "No avaliable flights registred.\n";
	else
		while (flights != avaliable_flights.end())
		{
			output << "> " << flights->second << "\n\t";
			++flights;
		}
	/* CAUTION! PRIVATE INFORMATION */
	output << "\nAlready sold " << num_sold_tickets << " tickets;\n";
	output << "Earn " << earned_money << "$ (of maximum " << max_amount_of_money << ");\n";
	output << "Paper remained " << paper_remained << ";\n";

	output << "\nList of returned tickets:\n\t";
	map<char*, ticket>::iterator tickets;
	tickets = returned_tickets.begin();
	if (tickets == returned_tickets.end())
		output << "No returned tickets.\n";
	else
		while (tickets != returned_tickets.end())
		{
			output << "#" << (tickets->second).number << " | Name of passenger: " << (tickets->second).passenger << " | Route: " << (tickets->second).route << "\n\t";
			++tickets;
		}
	output << "\nSold Tickets:\n\t";
	tickets = sold_tickets.begin();
	if (tickets == sold_tickets.end())
		output << "No sold tickets.\n";
	else
		while (tickets != sold_tickets.end())
		{
			output << "#" << (tickets->second).number << " | Name of passenger: " << (tickets->second).passenger << " | Route: " << (tickets->second).route << "\n\t";
			++tickets;
		}

	cout << "\n<<< Information about CashRegister#" << number << " written to file. >>>\n";

	output.close();
}
// input
int CashRegister::initClass()
{
	cout << "__________________________________________________________________________\n";
	cout << "Please enter max amount money for cash register before cash collection: ";
	cin >> max_amount_of_money;
	if (max_amount_of_money < 0)
		max_amount_of_money = -max_amount_of_money;
	cout << "Please enter amount of paper: ";
	int paper_remained_prot;
	cin >> paper_remained_prot;
	paper_remained = (paper_remained_prot < 0) ? -paper_remained_prot : paper_remained_prot;

	cout << "Please enter work hours of this cash:\n\t";
	char *nameOfDays[7] = { { "Monday: " },{ "Tuesday: " },{ "Wednesday: " } ,{ "Thursday: " } ,{ "Friday: " } ,{ "Saturday: " } ,{ "Sunday: " } };
	
	for (int i = 0; i < 7; ++i)
	{
		cout << nameOfDays[i] << "\n\t";
		cout << "| Work starts: ";
		cin >> work_hours[0][i];
		cout << "\t| Work ends: ";
		cin >> work_hours[1][i];
		cout << "\t";
		
	}

	cout << "Please enter avaliable flights (\"Q\" for quit):\n\t";
	char *flight = new char[20];
	while ()
	{

	}

	return 1;
}
int CashRegister::initClassFromFile()
{
	char cashRegister[10];
	_itoa_s(number, cashRegister, 10, 10);

	/* strcat_s somewhy don't work with dynamic memory. */

	char str[40];
	strcpy_s(str, "CashRegister#");
	strcat_s(str, cashRegister);
	strcat_s(str, ".txt");

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
		if (i != 6)
		{
			while ((ch = init.get()) != 9); // horizontal tab = 9
			init.seekg(12, ios::cur);
		}
	}
	while ((ch = init.get()) != ':'); // :
	init.seekg(3, ios::cur);
	
	// Aval flights.

	init.close();
	cout << "\n<<< Information about CashRegister#" << number << " initialized from file. >>>\n";

	return 1;
}
//for updating prog
void CashRegister::sold(char* flightLocation, char* passangerName, size_t amount_of_tickets)
{
	/* SHOULD FIND IN MAP flightLocation */
	bool isFlightPossible = false; // NOT WRITTEN
	bool isPaperEnough = (amount_of_tickets <= paper_remained) ? true : false;
	
	// price also
}
