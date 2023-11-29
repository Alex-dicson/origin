#pragma once
#include "air_tv.h"
#include "macros.h"

class Eagle : public Air
{
public:
	LIBTV_API Eagle();
	LIBTV_API double calc(int distance) override;
};