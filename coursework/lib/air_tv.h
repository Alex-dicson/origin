#pragma once
#include "tv.h"
#include "macros.h"

class LIBTV_API Air : public Vehicle
{
protected:
	int _speed;
public:
	Air();
	double calc(int distance) override;
};