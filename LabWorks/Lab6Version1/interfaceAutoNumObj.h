#pragma once

class interfaceAutoNumObj
{
public:
	interfaceAutoNumObj();
	~interfaceAutoNumObj();

	virtual int numOfObj() = 0;
	virtual int amountOfObj() = 0;
};