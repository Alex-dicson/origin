#pragma once
#include "quadrangle.h"
#ifdef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

class Parallelogram : public Quadrangle
{
public:
	FIGLIB_API Parallelogram(int ac, int bd, int AC, int BD);

};