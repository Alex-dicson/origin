#include "broom.h"

Broom::Broom()
{
	_type = 2;
	_name = (L"Метла");
	_speed = 20;
}

double Broom::calc(int distance)
{
	int tmp;
	tmp = distance / 1000;
	return ((distance * (1 - (double(tmp) / 100))) / _speed);
}