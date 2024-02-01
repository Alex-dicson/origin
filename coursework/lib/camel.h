#pragma once
#include "ground_tv.h"

class LIBTV_API Camel : public Ground
{
public:
	Camel();
	double calc(int distance) override;

};