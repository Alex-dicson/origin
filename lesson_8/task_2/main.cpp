#include <iostream>
#include <Windows.h>
#include "figure.h"
#include "triangle.h"
#include "isosceles.h"
#include "equilateral.h"
#include "right.h"
#include "quadrangle.h"
#include "rectangles.h"
#include "sqare.h"
#include "parallelogram.h"
#include "rhomb.h"


using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Triangle triangle(10, 20, 30, 50, 60, 70); 
	Right right(10, 20, 30, 40, 50, 90);
	Isosceles isosceles(40, 20, 40, 70, 40, 70);
	Equilateral equilateral(30, 30, 30, 60, 60, 60);
	Quadrangle quadrangle(10, 20, 30, 60, 100, 80, 90, 90);
	Rectangles rectangle(10, 20, 10, 20, 90, 90, 90, 90);
	Sqare sqare(20, 20, 20, 20, 90, 90, 90, 90);
	Parallelogram parallelogram(30, 20, 30, 20, 110, 70, 110, 70);
	Rhomb rhomb(30, 30, 30, 30, 100, 80, 100, 80);
	return 0;
}