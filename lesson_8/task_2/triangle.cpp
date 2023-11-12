#include "triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
{
	sides_count = 3;
	name = "Треугольник";
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	try
	{
		if (A+B+C != 180)
		{
			throw Err_Figure("сумма углов не равна 180");
		}
		else if (sides_count != 3)
		{
			throw Err_Figure("количество сторон не равна 3");
		}		
		cout << name <<  " (стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") создан" << endl;
	}
	catch (const Err_Figure& err)
	{
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl;

	}
	catch (...)
	{
		cout << "Ошибка создания фигуры. Причина: Неизвестная ошибка";
	}
	
	
	
}
Triangle::Triangle(string name, int a, int b, int c, int A, int B, int C)
{
	sides_count = 3;
	this->name = name;
	this->a = a;
	this->b = b;
	this->c = c;
	this->A = A;
	this->B = B;
	this->C = C;
	try
	{
		if (A + B + C != 180)
		{
			throw Err_Figure("сумма углов не равна 180");
		}
		else if (sides_count != 3)
		{
			throw Err_Figure("количество сторон не равна 3");
		}
		else if (name == "Прямоугольный треугольник" && C != 90)
		{
			throw Err_Figure("угол С не равен 90 градусов");
		}
		else if (name == "Равносторонний треугольник")
		{
			if (a != b && b != c)
			{
				throw Err_Figure("стороны не равны");
			}
			else if (A != 60 && B != 60 && C != 60)
			{
				throw Err_Figure("углы не равны 60 градусам");
			}
		}
		else if (name == "Равнобедренный треугольник")
		{
			if (a != c)
			{
				throw Err_Figure("стороны a и c не равны");
			}
			else if (A != C)
			{
				throw Err_Figure("углы A и C не равны");
			}
		}

		cout << name <<  " (стороны " << a << ", " << b << ", " << c << "; углы " << A << ", " << B << ", " << C << ") создан" << endl;
	}
	catch (const Err_Figure& err)
	{
		cout << "Ошибка создания фигуры. Причина: " << err.what() << endl;

	}
	catch (...)
	{
		cout << "Ошибка создания фигуры. Причина: Неизвестная ошибка";
	}
}
int Triangle::get_a()
{
	return a;
}
int Triangle::get_b()
{
	return b;
}
int Triangle::get_c()
{
	return c;
}
int Triangle::get_A()
{
	return A;
}
int Triangle::get_B()
{
	return B;
}
int Triangle::get_C()
{
	return C;
}