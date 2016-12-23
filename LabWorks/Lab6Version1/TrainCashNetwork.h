#pragma once
#include "pbDeliveredFromCashRegister.h"
#include "IAutoNumObj.h"
#include "IConvertObjToStr.h"
class TrainCashNetwork : public pbDeliveredFromCashRegister, public IConvertObjToStr, public IAutoNumObj
{
public:
	TrainCashNetwork();
	~TrainCashNetwork();

	virtual int convertObjToStr(string& str);
	virtual int convertStrToObj(string& str);

	virtual int numOfObj() { return (this->number); };
	virtual int amountOfObj() { return ((this->freeCashNum) - 10000); };
	
	virtual void Sort(IAutoNumObj *obj);
	virtual ostream& operator<<(ostream &str);
	virtual istream& operator>>(istream &str);

	friend void convertElemObjToStr(char*,const size_t&,const size_t&);
};

