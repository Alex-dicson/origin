#pragma once
#include "parallelogram.h"
class Rectangles : public  Parallelogram
{
protected:
	Rectangles(string name, int a, int b, int c, int d, int A, int B, int C, int D);

public:
	Rectangles(int a, int b, int c, int d, int A, int B, int C, int D);
};