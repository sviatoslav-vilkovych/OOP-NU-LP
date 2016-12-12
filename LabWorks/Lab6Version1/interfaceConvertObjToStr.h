#pragma once
#include "header.h"
class interfaceConvertObjToStr
{
public:
	interfaceConvertObjToStr();
	~interfaceConvertObjToStr();

	virtual int convertObjToStr(string& str) = 0;
	virtual int convertStrToObj(string& str) = 0;
};

