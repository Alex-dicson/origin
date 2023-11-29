#include "carpet.h"

Carpet::Carpet()
{
	_type = 2;
	_name = (L"Ковер-самолет");
	_speed = 10;
}

double Carpet::calc(int distance)
{
	if (distance < 1000)
	{
		return distance / _speed;
	}
	else if (distance >= 1000 || distance < 5000)
	{
		return (distance * 0.97) / _speed;
	}
	else if (distance >= 5000 || distance < 10000)
	{
		return (distance * 0.9) / _speed;
	}
	else if (distance >= 10000)
	{
		return (distance * 0.95) / _speed;
	}
	else
	{
		return distance / _speed;
	}
}