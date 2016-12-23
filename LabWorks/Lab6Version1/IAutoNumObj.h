#pragma once

class IAutoNumObj
{
public:
	IAutoNumObj();
	~IAutoNumObj();

	virtual int numOfObj() = 0;
	virtual int amountOfObj() = 0;
};