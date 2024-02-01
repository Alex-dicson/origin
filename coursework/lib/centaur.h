#pragma once
#include "ground_tv.h"

class LIBTV_API Centaur : public Ground
{
public:
	Centaur();
	double calc(int distance) override;
};