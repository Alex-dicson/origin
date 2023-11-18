#include <iostream>

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
	bool operator==(const Fraction& right) const
	{
		if (double(numerator_ / denominator_) == double(right.numerator_ / right.denominator_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator!=(const Fraction& right) const
	{
		if (double(numerator_ / denominator_) != double(right.numerator_ / right.denominator_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<(const Fraction& right) const
	{
		if (double(numerator_ / denominator_) < double(right.numerator_ / right.denominator_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>(const Fraction& right) const
	{
		if ((double(numerator_ / denominator_) > double(right.numerator_ / right.denominator_)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator<=(const Fraction& right) const
	{
		if (double(numerator_ / denominator_) <= double(right.numerator_ / right.denominator_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool operator>=(const Fraction& right) const
	{
		if (double(numerator_ / denominator_) >= double(right.numerator_ / right.denominator_))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	const Fraction f1(4, 3);
	const Fraction f2(4, 3);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}