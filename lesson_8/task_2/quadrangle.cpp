#include "quadrangle.h"


Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
{
	sides_count = 4;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	name = "Четырехугольник";
	try
	{
		if (A + B + C + D != 360)
		{
			throw Err_Figure("сумма углов не равна 360");
		}
		else if (sides_count != 4)
		{
			throw Err_Figure("количество сторон не равно 4");
		}
		cout << name << " (стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D <<") создан" << endl;
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

Quadrangle::Quadrangle(string name, int a, int b, int c, int d, int A, int B, int C, int D)
{
	sides_count = 4;
	this->name = name;
	this->a = a;
	this->b = b;
	this->c = c;
	this->d = d;
	this->A = A;
	this->B = B;
	this->C = C;
	this->D = D;
	try
	{
		if (A + B + C + D != 360)
		{
			throw Err_Figure("сумма углов не равна 360");
		}
		else if (sides_count != 4)
		{
			throw Err_Figure("количество сторон не равно 4");
		}
		else if (name == "Прямоугольник")
		{
			if (a != c && b != d)
			{
				throw Err_Figure("стороны a и с(b и d) не равны");
			}
			if (A != 90 && B != 90 && C != 90 && D != 90)
			{
				throw Err_Figure("углы не равны 90 градусов");
			}	
		}
		else if (name == "Квадрат")
		{
			if (a != b && b != c && c != d)
			{
				throw Err_Figure("стороны не равны");
			}
			if (A != 90 && B != 90 && C != 90 && D != 90)
			{
				throw Err_Figure("углы не равны 90 градусов");
			}
		}
		else if (name == "Параллелограм")
		{
			if (a != c && b != d)
			{
				throw Err_Figure("стороны a и c(b и d) не равны");
			}
			else if (A != C && B != D)
			{
				throw Err_Figure("углы A и C(B и D) не равны");
			}
		}
		else if (name == "Ромб")
		{
			if (a != b && b != c && c != d)
			{
				throw Err_Figure("стороны не равны");
			}
			else if (A != C && B != D)
			{
				throw Err_Figure("углы A и C(B и D) не равны");
			}
		}

		cout << name << " (стороны " << a << ", " << b << ", " << c << ", " << d << "; углы " << A << ", " << B << ", " << C << ", " << D << ") создан" << endl;
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

int Quadrangle::get_a()
{
	return a;
}
int Quadrangle::get_b()
{
	return b;
}
int Quadrangle::get_c()
{
	return c;
}
int Quadrangle::get_d()
{
	return d;
}
int Quadrangle::get_A()
{
	return A;
}
int Quadrangle::get_B()
{
	return B;
}
int Quadrangle::get_C()
{
	return C;
}
int Quadrangle::get_D()
{
	return D;
}