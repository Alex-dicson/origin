#include "rectangles.h"

Rectangles::Rectangles(int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram("Прямоугольник", a, b, c, d, A, B, C, D) {};
Rectangles::Rectangles(string name, int a, int b, int c, int d, int A, int B, int C, int D) : Parallelogram(name, a, b, c, d, A, B, C, D) {};