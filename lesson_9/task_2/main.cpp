#include <iostream>
#include <Windows.h>
using namespace std;

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	Fraction operator+(Fraction& right)
	{
		return calculation_fraction(*this, right, "+");
	}
	Fraction operator-(Fraction& right)
	{
		return calculation_fraction(*this, right, "-");
	}
	Fraction operator*(Fraction& right)
	{
		return calculation_fraction(*this, right, "*");
	}
	Fraction operator/(Fraction& right)
	{
		return calculation_fraction(*this, right, "/");
	}
	Fraction& operator++()
	{
		Fraction inkr(denominator_, denominator_);
		*this = calculation_fraction(*this, inkr, "+");
		return *this;
	}
	Fraction& operator--(int)
	{
		Fraction dekr(denominator_, denominator_);
		*this = calculation_fraction(*this, dekr, "-");
		return *this;
	}

	friend Fraction calculation_fraction(Fraction left, Fraction right, string oper);
	friend ostream& operator<<(ostream& left, Fraction right);
	//friend ostream& operator<<(Fraction left, ostream& right);
};

ostream& operator<<(ostream& left, Fraction right)
{
	left << right.numerator_ << "/" << right.denominator_;
	return left;
}
//ostream& operator<<(Fraction left, ostream& right)
//{
//	right << left.numerator_ << "/" << left.denominator_;
//	return right;
//}

Fraction calculation_fraction(Fraction left, Fraction right, string oper)
{
	int num = 0, denom = 0;
	if (oper == "+")
	{
		num = abs((left.numerator_ * right.denominator_) + (right.numerator_ * left.denominator_));
		denom = abs(left.denominator_ * right.denominator_);
	}
	else if (oper == "-")
	{
		num = abs((left.numerator_ * right.denominator_) - (right.numerator_ * left.denominator_));
		denom = abs(left.denominator_ * right.denominator_);
	}
	else if (oper == "*")
	{
		num = abs(left.numerator_ * right.numerator_);
		denom = abs(left.denominator_ * right.denominator_);
	}
	else if (oper == "/")
	{
		num = abs(left.numerator_ * right.denominator_);
		denom = abs(left.denominator_ * right.numerator_);
	}

	while (num != denom)
	{
		if (denom > num)
		{
			denom = denom - num;
		}
		else
		{
			num = num - denom;
		}

	}
	if (oper == "+")
	{
		return Fraction(((left.numerator_ * right.denominator_) + (right.numerator_ * left.denominator_)) / denom, (left.denominator_ * right.denominator_) / denom);
	}
	else if (oper == "-")
	{
		return Fraction(((left.numerator_ * right.denominator_) - (right.numerator_ * left.denominator_)) / denom, (left.denominator_ * right.denominator_) / denom);
	}
	else if (oper == "*")
	{
		return Fraction((left.numerator_ * right.numerator_) / denom, (left.denominator_ * right.denominator_) / denom);
	}
	else if (oper == "/")
	{
		return Fraction((left.numerator_ * right.denominator_) / denom, (left.denominator_ * right.numerator_) / denom);
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int num1, num2, denom1, denom2;
	cout << "Введите числитель дроби 1: ";
	cin >> num1;
	cout << "Введите знаменатель дроби 1: ";
	cin >> denom1;
	cout << "Введите числитель дроби 2: ";
	cin >> num2;
	cout << "Введите знаменатель дроби 2: ";
	cin >> denom2;
	Fraction f1(num1, denom1);
	Fraction f2(num2, denom2);
	cout << f1 << " + " << f2 << " = " << (f1 + f2) << endl;
	cout << f1 << " - " << f2 << " = " << (f1 - f2) << endl;
	cout << f1 << " * " << f2 << " = " << (f1 * f2) << endl;
	cout << f1 << " / " << f2 << " = " << (f1 / f2) << endl;
	cout << "++" << f1;
	cout << " * " << f2 << " = " << (++f1 * f2) << endl;
	cout << "Значение дроби 1 = " << f1 << endl;
	cout << f1;
	cout << "--" << " * " << f2 << " = " << (f1 * f2) << endl;
	cout << "Значение дроби 1 = " << f1-- << endl;
	return 0;
}
