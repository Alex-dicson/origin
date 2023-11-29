#include "tv.h"

Vehicle::Vehicle()
{
	_name = (L"Транспортное средство");	// имя трансопртного средства
	_type = 0;							//тип транспортного средства 1 - наземное, 2 - воздушное, 0 - не определено
}

Vehicle::~Vehicle() {}

wstring Vehicle::get_name()
{
	return _name;
}

double Vehicle::calc(int distance)
{
	return 0;
}
