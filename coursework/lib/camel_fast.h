#pragma once
#include "ground_tv.h"

class LIBTV_API CamelFast : public Ground
{
public:
	CamelFast();
	double calc(int distance) override;
};