#pragma once
#include "parallelogram.h"
#include "macros.h"

class Rectangle : public  Parallelogram
{
public:
	FIGLIB_API Rectangle(int ac, int bd);
};