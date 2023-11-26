#pragma once
#include <iostream>
#include "figure.h"
#include "macros.h"
using namespace std;


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