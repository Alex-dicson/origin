#pragma once
#include "quadrangle.h"

class Parallelogram : public Quadrangle
{
protected:
	Parallelogram(string name, int a, int b, int c, int d, int A, int B, int C, int D);
public:
	Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D);

};