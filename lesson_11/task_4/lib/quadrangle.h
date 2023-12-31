﻿#pragma once
#include <iostream>
#include "figure.h"
#include "macros.h"
using namespace std;

class Quadrangle : public Figure
{
protected:
	int a, b, c, d;
	int A, B, C, D;
public:
	FIGLIB_API Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
	FIGLIB_API int get_a();
	FIGLIB_API int get_b();
	FIGLIB_API int get_c();
	FIGLIB_API int get_d();
	FIGLIB_API int get_A();
	FIGLIB_API int get_B();
	FIGLIB_API int get_C();
	FIGLIB_API int get_D();
	FIGLIB_API void print() override;


};