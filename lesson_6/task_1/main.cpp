#include <iostream>
#include "addition.h"
#include "subtraction.h"
#include "degree.h"
#include "division.h"
#include "multiplication.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b, value;
	cout << "Введите первое число: ";
	cin >> a;
	cout << "Введите второе число: ";
	cin >> b;
	cout << "Выберите операцию (1 - сложение, 2 вычитание, 3 - умножение, 4 - деление, 5 - возведение в степень): ";
	cin >> value;
	if (value == 1)
	{
		cout << a << " плюс " << b << " = " << addition(a, b) << endl;
	}
	else if (value == 2)
	{
		cout << a << " вычесть " << b << " = " << subtraction(a, b) << endl;
	}
	else if (value == 3)
	{
		cout << a << " умножить " << b << " = " << multiplication(a, b) << endl;
	}
	else if (value == 4)
	{
		cout << a << " разделить " << b << " = " << division(a, b) << endl;
	}
	else if (value == 5)
	{
		cout << a << " в степени " << b << " = " << degree(a, b) << endl;
	}
	else
	{
		cout << "Вы не правильно ввели операцию!";

	}
	return 0;
}