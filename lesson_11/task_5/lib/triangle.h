#pragma once
#include <iostream>
#include "figure.h"
using namespace std;
#ifndef LIB_EXPORTS
#define FIGLIB_API __declspec(dllexport)
#else
#define FIGLIB_API __declspec(dllimport)
#endif // FIGLIB_EXPORTS

class Triangle : public Figure
{
protected:
	int a, b, c;
	int A, B, C;

public:
	FIGLIB_API Triangle(int a, int b, int c, int A, int B, int C);
	FIGLIB_API int get_a();
	FIGLIB_API int get_b();
	FIGLIB_API int get_c();
	FIGLIB_API int get_A();
	FIGLIB_API int get_B();
	FIGLIB_API int get_C();
	FIGLIB_API void print() override;

};