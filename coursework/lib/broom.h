#pragma once
#include "air_tv.h"
#include "macros.h"

class Broom : public Air
{
public:
	LIBTV_API Broom();
	LIBTV_API double calc(int distance) override;
};