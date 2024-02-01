#pragma once
#include "air_tv.h"
#include "macros.h"

class LIBTV_API Eagle : public Air
{
public:
	Eagle();
	double calc(int distance) override;
};