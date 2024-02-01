#pragma once
#include "ground_tv.h"

class LIBTV_API Boots : public Ground
{
public:
	Boots();
	double calc(int distance) override;
};