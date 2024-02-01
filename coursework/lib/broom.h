#pragma once
#include "air_tv.h"
#include "macros.h"

class LIBTV_API Broom : public Air
{
public:
	Broom();
	double calc(int distance) override;
};