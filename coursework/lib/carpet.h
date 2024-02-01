#pragma once
#include "air_tv.h"
#include "macros.h"

class LIBTV_API Carpet : public Air
{
public:
	Carpet();
	double calc(int distance) override;
};