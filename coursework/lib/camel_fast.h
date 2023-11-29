#pragma once
#include "ground_tv.h"

class CamelFast : public Ground
{
public:
	LIBTV_API CamelFast();
	LIBTV_API double calc(int distance) override;
};