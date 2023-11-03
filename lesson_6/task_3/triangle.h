#pragma once
#include <iostream>
#include "figure.h"
using namespace std;

class Triangle : public Figure
{
protected:
	int a, b, c;
	int A, B, C;

public:
	Triangle(int a, int b, int c, int A, int B, int C);
	int get_a();
	int get_b();
	int get_c();
	int get_A();
	int get_B();
	int get_C();
	void print() override;

};