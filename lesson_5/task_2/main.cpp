#include <iostream>

using namespace std;

class Figure
{
protected:
	string name;
public:
	Figure()
	{
		name = "������";
	}
	virtual void print(){}

};

class Triangle : public Figure
{
protected:
	int a, b, c;
	int A, B, C;
	
public:
	Triangle(int a,int b,int c, int A, int B, int C)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		name = "�����������";
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
	void print() override
	{
		cout << name << ":" << endl;
		cout << "�������:" << " a=" << get_a() << " b=" << get_b() << " c=" << get_c() << endl;
		cout << "����:" << " A=" << get_A() << " B=" << get_B() << " C=" << get_C() << endl;
	}

};

class Right : public Triangle
{
public:
	Right(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90){ name = "������������� �����������"; }

};

class Isosceles : public Triangle
{
public:
	Isosceles(int ac, int b, int AC, int B) : Triangle(ac, b, ac, AC, B, AC){ name = "�������������� �����������"; }

};

class Equilateral : public Triangle
{
public:
	Equilateral(int a): Triangle(a, a, a, 60, 60, 60){ name = "�������������� �����������"; }

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
		name = "���������������";
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
	void print() override
	{
		cout << name << ":" << endl;
		cout << "�������:" << " a=" << get_a() << " b=" << get_b() << " c=" << get_c() << " d=" << get_d() << endl;
		cout << "����:" << " A=" << get_A() << " B=" << get_B() << " C=" << get_C() << " D=" << get_D() << endl;
	}


};

class Parallelogram : public Quadrangle
{
public:
	Parallelogram(int ac, int bd, int AC, int BD) : Quadrangle(ac, bd, ac, bd, AC, BD, AC, BD) { name = "�������������"; }

};

class Rhomb : public Parallelogram
{
public:
	Rhomb(int a, int AC, int BD) : Parallelogram(a, a, AC, BD) { name = "�������������"; }


};

class Rectangle : public  Parallelogram
{
public:
	Rectangle(int ac, int bd) : Parallelogram(ac, bd, 90, 90){ name = "�������������"; }
};

class Sqare : public Rectangle
{
public:
	Sqare(int a) : Rectangle(a, a){ name = "�������������"; }

};



void print_info(Figure* figure) 
{
	figure->print();

}


int main()
{
	setlocale(LC_ALL, "Russian");
	Triangle triangle(10, 20 ,30 , 50 ,60 ,70);
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