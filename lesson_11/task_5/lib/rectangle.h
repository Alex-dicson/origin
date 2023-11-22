#pragma once
#include "parallelogram.h"
#ifndef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

class Rectangle : public  Parallelogram
{
public:
	FIGLIB_API Rectangle(int ac, int bd);
};