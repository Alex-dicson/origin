#pragma once
#include "ground_tv.h"

class Camel : public Ground
{
public:
	LIBTV_API Camel();
	LIBTV_API double calc(int distance) override;

};