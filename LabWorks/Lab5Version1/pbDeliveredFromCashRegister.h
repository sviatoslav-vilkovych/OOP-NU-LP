#pragma once
#include "CashRegister.h"
class pbDeliveredFromCashRegister : public CashRegister
{
public:
	pbDeliveredFromCashRegister();
	~pbDeliveredFromCashRegister();

	//virtual bool operator<(Cash& ob2) { return ((machine == ob2.machine) && (number < ob2.number)); };
};

