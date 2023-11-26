#pragma once
#include <iostream>
#include "macros.h"

using namespace std;

class Figure
{
protected:
	string name;
public:
	FIGLIB_API Figure();
	FIGLIB_API virtual void print();

};