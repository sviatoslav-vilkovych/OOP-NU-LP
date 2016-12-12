#pragma once
#include "pbDeliveredFromCashRegister.h"
#include "interfaceAutoNumObj.h"
#include "interfaceConvertObjToStr.h"
class TrainCashNetwork : public pbDeliveredFromCashRegister, public interfaceConvertObjToStr, public interfaceAutoNumObj
{
public:
	TrainCashNetwork();
	~TrainCashNetwork();

	virtual int convertObjToStr(string& str);
	virtual int convertStrToObj(string& str);

	virtual int numOfObj() { return (this->number); };
	virtual int amountOfObj() { return ((this->freeCashNum) - 10000); };

	virtual void Sort(interfaceAutoNumObj *obj);
	virtual ofstream& operator<<(ofstream &str);
	virtual ofstream& operator<<(ofstream &str);
};

