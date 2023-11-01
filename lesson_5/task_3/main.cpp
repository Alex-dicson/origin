#include <iostream>

using namespace std;

class Figure
{
protected:
	int sides_count;
	string name;
	bool value;
public:
	Figure()
	{
		name = "Фигура";
		sides_count = 0;
	}
	virtual void print_info() 
	{
		cout << endl;
		cout << name << ":" << endl;
		if (this ->check() == true) {
			cout << "Правильная" << endl;
		}
		else
		{
			cout << "Неправильная" << endl;
		}
		cout << "Количество сторон: " << sides_count << endl;
	}
	virtual bool check()
	{
		return sides_count == 0 ? true : false;
	}

};

class Triangle : public Figure
{
protected:
	int a, b, c;
	int A, B, C;

public:
	Triangle(int a, int b, int c, int A, int B, int C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		name = "Треугольник";
		sides_count = 3;
	}
	int get_a()
	{
		return a;
	}
	int get_b()
	{
		return b;
	}
	int get_c()
	{
		return c;
	}
	int get_A()
	{
		return A;
	}
	int get_B()
	{
		return B;
	}
	int get_C()
	{
		return C;
	}
	void print_info() override
	{
		Figure::print_info();
		cout << "Стороны:" << " a=" << get_a() << " b=" << get_b() << " c=" << get_c() << endl;
		cout << "Углы:" << " A=" << get_A() << " B=" << get_B() << " C=" << get_C() << endl;
	}
	bool check() override
	{

		return (A + B + C == 180 && sides_count == 3) ? true : false;
	}

};

class Right : public Triangle
{
public:
	Right(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) { name = "Прямоугольный треугольник"; }

	bool check() override
	{
		return (Triangle::check() == true && C == 90) ? true : false;
	}

};

class Isosceles : public Triangle
{
public:
	Isosceles(int ac, int b, int AC, int B) : Triangle(ac, b, ac, AC, B, AC) { name = "Равнобедренный треугольник"; }
	bool check() override
	{
		return (Triangle::check() == true && a == c && A == C) ? true : false;
	}
};

class Equilateral : public Triangle
{
public:
	Equilateral(int a) : Triangle(a, a, a, 60, 60, 60) { name = "Равносторонний треугольник"; }

	bool check() override
	{
		return (Triangle::check() == true && a == b && b == c && A == 60 && B == 60 && C == 60) ? true : false;
	}
};

class Quadrangle : public Figure
{
protected:
	int a, b, c, d;
	int A, B, C, D;
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		name = "Четырехугольник";
		sides_count = 4;
	}
	int get_a()
	{
		return a;
	}
	int get_b()
	{
		return b;
	}
	int get_c()
	{
		return c;
	}
	int get_d()
	{
		return d;
	}
	int get_A()
	{
		return A;
	}
	int get_B()
	{
		return B;
	}
	int get_C()
	{
		return C;
	}
	int get_D()
	{
		return D;
	}
	void print_info() override
	{
		Figure::print_info();
		cout << "Стороны:" << " a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << endl;
		cout << "Углы:" << " A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << endl;
	}
	bool check() override
	{

		return (A + B + C + D == 360 && sides_count == 4) ? true : false;
	}

};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int ac, int bd, int AC, int BD) : Quadrangle(ac, bd, ac, bd, AC, BD, AC, BD) { name = "Параллелограм"; }

	bool check() override
	{

		return (Quadrangle::check() && a == c && b == d && A == C && B == C) ? true : false;
	}
};

class Rhomb : public Parallelogram
{
public:
	Rhomb(int a, int AC, int BD) : Parallelogram(a, a, AC, BD) { name = "Ромб"; }

	bool check() override
	{

		return (Quadrangle::check() && a == b && b == c && c == d && A == C && B == D) ? true : false;
	}

};

class Rectangle : public  Parallelogram
{
public:
	Rectangle(int ac, int bd) : Parallelogram(ac, bd, 90, 90) { name = "Прямоугольник"; }

	bool check() override
	{

		return (Quadrangle::check() && a == c && b == d && A == B && B == C && C == D && D == 90) ? true : false;
	}
};

class Sqare : public Rectangle
{
public:
	Sqare(int a) : Rectangle(a, a) { name = "Квадрат"; }

	bool check() override
	{

		return (Quadrangle::check() && a == b && b == c && c == d && A == B && B == C && C == D && D == 90) ? true : false;
	}

};


int main()
{
	setlocale(LC_ALL, "Russian");
	Figure fig;
	fig.print_info();
	Triangle triangle(10, 20, 30, 50, 60, 70);
	triangle.print_info();
	Right right(10, 20, 30, 50, 40);
	right.print_info();
	Isosceles isosceles(10, 20, 50, 60);
	isosceles.print_info();
	Equilateral equilateral(30);
	equilateral.print_info();
	Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
	quadrangle.print_info();
	Rectangle rectangle(10, 20);
	rectangle.print_info();
	Sqare sqare(20);
	sqare.print_info();
	Parallelogram parallelogram(20, 30, 30, 40);
	parallelogram.print_info();
	Rhomb rhomb(30, 30, 40);
	rhomb.print_info();
	return 0;
}