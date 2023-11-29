#pragma once
#include <iostream>
#include "macros.h"
using namespace std;



//Создаем родительский класс transport vehicle
class Vehicle
{
protected:
	int _type;
	wstring _name;

public:
	LIBTV_API Vehicle();
	LIBTV_API ~Vehicle();
	LIBTV_API virtual wstring get_name();
	LIBTV_API virtual double calc(int distance);

};
