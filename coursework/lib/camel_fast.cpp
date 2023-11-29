#include "camel_fast.h"

CamelFast::CamelFast()
{
	_type = 1;
	_name = (L"Верблюд-быстроход");
	_speed = 40;
	_driving_time = 10;

}

double CamelFast::calc(int distance)
{
	double time_no_rest = 0;		// переменная что бы понять сколько нужно вермени пройти расстояние без учета отдыха
	int quantity_rest = 0;			// сколько раз нужно отдохнуть
	double time_rest = 0;		// сколько времени нужно на отдых
	time_no_rest = distance / _speed;
	quantity_rest = time_no_rest / _driving_time;

	if (quantity_rest > 2)
	{
		time_rest = (5 + 6.5 + ((quantity_rest - 2) * 8));
	}
	else if (quantity_rest == 2)
	{
		time_rest = 5 + 6.5;
	}
	else if (quantity_rest == 1)
	{
		time_rest = 5;
	}
	return time_no_rest + time_rest;
}