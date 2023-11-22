#include <iostream>
#include "figure.h"
#include "triangle.h"
#include "isosceles.h"
#include "equilateral.h"
#include "right.h"
#include "quadrangle.h"
#include "rectangle.h"
#include "sqare.h"
#include "parallelogram.h"
#include "rhomb.h"

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