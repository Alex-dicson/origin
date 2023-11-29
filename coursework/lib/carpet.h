#pragma once
#include "air_tv.h"
#include "macros.h"

class Carpet : public Air
{
public:
	LIBTV_API Carpet();
	LIBTV_API double calc(int distance) override;
};