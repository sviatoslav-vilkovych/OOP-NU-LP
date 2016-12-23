#include "TrainCashNetwork.h"



TrainCashNetwork::TrainCashNetwork()
{
}
TrainCashNetwork::~TrainCashNetwork()
{
}

int TrainCashNetwork::convertObjToStr(string & str)
{
	
	// convertElemObjToStr

	return 0;
}

int TrainCashNetwork::convertStrToObj(string & str)
{

	return 0;
}

void TrainCashNetwork::Sort(IAutoNumObj * obj)
{
}

ostream & TrainCashNetwork::operator<<(ostream & str)
{
	// TODO: insert return statement here
}

istream & TrainCashNetwork::operator >> (istream & str)
{
	// TODO: insert return statement here
}

void convertElemObjToStr(char *pStr, const size_t& elem, const size_t&size)
{
	//dyn cast
	char *cElem= new char[size+1];
	_itoa(elem, cElem, size);
	cElem[size] = '\0';
	for (int i = 0; cElem[i] != '\0'; *pStr = cElem[i++])
		pStr++;
}
