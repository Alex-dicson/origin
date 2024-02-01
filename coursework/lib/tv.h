#pragma once
#include <iostream>
#include "macros.h"
using namespace std;



//Создаем родительский класс transport vehicle
class LIBTV_API Vehicle
{
protected:
	int _type;
	wstring _name;

public:
	Vehicle();
	~Vehicle();
	virtual wstring get_name();
	virtual double calc(int distance);

};
