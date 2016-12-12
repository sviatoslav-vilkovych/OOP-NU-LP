#pragma once
#include "pbDeliveredFromCashRegister.h"
#include "interfaceAutoNumObj.h"
#include "interfaceConvertObjToStr.h"

class CashTickets :
	public pbDeliveredFromCashRegister, public interfaceConvertObjToStr, public interfaceAutoNumObj
{
public:
	CashTickets();
	~CashTickets();

	virtual interfaceConvertObjToStr* convertOBjToStr(string& str);
};

