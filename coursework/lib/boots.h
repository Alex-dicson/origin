#pragma once
#include "ground_tv.h"

class Boots : public Ground
{
public:
	LIBTV_API Boots();
	LIBTV_API double calc(int distance) override;
};