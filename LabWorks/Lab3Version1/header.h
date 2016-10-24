#pragma once

#include <iostream>
#include <string.h>
#include <fstream>
#include <iomanip>
#include <map>
using namespace std;



struct ticket {
	size_t number;
	char *passenger;
	char *route;
};