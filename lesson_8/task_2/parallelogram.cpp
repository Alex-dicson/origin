#include "parallelogram.h"

Parallelogram::Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle("Параллелограм", a, b, c, d, A, B, C, D) {};
Parallelogram::Parallelogram(string name, int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(name, a, b, c, d, A, B, C, D) {};