#pragma once
#include "tv.h"
#include "macros.h"
using namespace std;

class Air : public Vehicle
{
protected:
	int _speed;
public:
	LIBTV_API Air();
	LIBTV_API double calc(int distance) override;
};