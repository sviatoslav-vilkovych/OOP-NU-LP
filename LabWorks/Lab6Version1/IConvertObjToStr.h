#pragma once
#include "header.h"
class IConvertObjToStr
{
public:
	IConvertObjToStr();
	~IConvertObjToStr();

	virtual int convertObjToStr(string& str) = 0;
	virtual int convertStrToObj(string& str) = 0;
};

