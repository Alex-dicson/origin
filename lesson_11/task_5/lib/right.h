#pragma once
#include "triangle.h"
#ifndef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

class Right : public Triangle
{
public:
	FIGLIB_API Right(int a, int b, int c, int A, int B);

};