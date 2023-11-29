#include "centaur.h"

Centaur::Centaur()
{
	_type = 1;
	_name = (L"Кентавр");
	_speed = 15;
	_driving_time = 8;
}

double Centaur::calc(int distance)
{
	double time_no_rest = 0;		// переменная что бы понять сколько нужно вермени пройти расстояние без учета отдыха
	int quantity_rest = 0;			// сколько раз нужно отдохнуть
	double time_rest = 0;		// сколько времени нужно на отдых
	time_no_rest = distance / _speed;
	quantity_rest = time_no_rest / _driving_time;

	if (quantity_rest > 1)
	{
		time_rest = quantity_rest * 2;
	}
	else if (quantity_rest == 1)
	{
		time_rest = 2;
	}
	return time_no_rest + time_rest;
}