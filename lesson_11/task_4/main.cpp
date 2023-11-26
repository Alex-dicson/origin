#include <iostream>
#include "lib/figure.h"
#include "lib/triangle.h"
#include "lib/isosceles.h"
#include "lib/equilateral.h"
#include "lib/right.h"
#include "lib/quadrangle.h"
#include "lib/rectangle.h"
#include "lib/sqare.h"
#include "lib/parallelogram.h"
#include "lib/rhomb.h"

using namespace std;



void print_info(Figure* figure)
{
	figure->print();

}


int main()
{
	setlocale(LC_ALL, "Russian");
	Triangle triangle(10, 20, 30, 50, 60, 70);
	print_info(&triangle);
	Right right(10, 20, 30, 50, 60);
	print_info(&right);
	Isosceles isosceles(10, 20, 50, 60);
	print_info(&isosceles);
	Equilateral equilateral(30);
	print_info(&equilateral);
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	print_info(&quadrangle);
	Rectangle rectangle(10, 20);
	print_info(&rectangle);
	Sqare sqare(20);
	print_info(&sqare);
	Parallelogram parallelogram(20, 30, 30, 40);
	print_info(&parallelogram);
	Rhomb rhomb(30, 30, 40);
	print_info(&rhomb);
	return 0;
}