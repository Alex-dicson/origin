#pragma once
#include "parallelogram.h"
#ifdef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

class Rhomb : public Parallelogram
{
public:
	FIGLIB_API Rhomb(int a, int AC, int BD);
};