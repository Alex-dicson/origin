#pragma once
#include "ground_tv.h"

class Centaur : public Ground
{
public:
	LIBTV_API Centaur();
	LIBTV_API double calc(int distance) override;
};