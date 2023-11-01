#include <iostream>

using namespace std;

class Figure
{
protected:
	int sides_count;
	string name;
public:
	Figure()
	{
		sides_count = 0;
		name = "Фигура";
	}
	int get_sides_count()
	{
		return sides_count;
	}
	string get_name()
	{
		return name;
	}
};

class Triangle : public Figure
{
public:
	Triangle()
	{
		sides_count = 3;
		name = "Треугольник";
	}

};

class Quadrangle : public Figure
{
public:
	Quadrangle()
	{
		sides_count = 4;
		name = "Четырёхугольник";
	}


};


int main() 
{
	setlocale(LC_ALL, "Russian");
	int in;
	cout << "Количество сторон: ";
	cin >> in;
	if (in == 3)
	{
		Triangle triangle;
		cout << triangle.get_name() << ": " << triangle.get_sides_count();
	}
	else if (in == 4)
	{
		Quadrangle quadrangle;
		cout << quadrangle.get_name() << ": " << quadrangle.get_sides_count();
	}
	else
	{
		Figure fig;
		cout << fig.get_name() << ": " << fig.get_sides_count();
	}
	return 0;
}