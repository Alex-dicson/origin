#pragma once
#include "triangle.h"
#ifndef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

class Isosceles : public Triangle
{
public:
	FIGLIB_API Isosceles(int ac, int b, int AC, int B);

};