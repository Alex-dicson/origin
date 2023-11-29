#include "eagle.h"

Eagle::Eagle()
{
	_type = 2;
	_name = (L"Орел");
	_speed = 8;
}

double Eagle::calc(int distance)
{
	return((distance * 0.94) / _speed);
}