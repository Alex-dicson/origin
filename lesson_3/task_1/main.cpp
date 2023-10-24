#include <iostream>
#include <string>

using namespace std;

class Calculator
{
private:
	double num1;
	double num2;
public:
	Calculator()
	{
		this->num1 = 0;
		this->num2 = 0;
	}
	double add()
	{
		return this->num1 + this->num2;
	}
	double multiply()
	{
		return this->num1 * this->num2;
	}
	double subtract_1_2()
	{
		return this->num2 - this->num1;
	}
	double subtract_2_1()
	{
		return this->num1 - this->num2;
	}
	double divide_1_2()
	{
		return this->num1 / this->num2;
	}
	double divide_2_1()
	{
		return this->num2 / this->num1;
	}
	bool set_num1(double num1)
	{
		this->num1 = num1;
		if (num1 != 0) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool set_num2(double num2)
	{
		this->num2 = num2;
		if (num2 != 0) 
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
	setlocale(LC_ALL, "Russian");
	Calculator calc;
	double num1, num2;
	while (true)
	{
		do
		{
			cout << "Введите num1: ";
			cin >> num1;
			if (!calc.set_num1(num1))
			{
				cout << "Некорректный ввод!" << endl;
			}

		} while (!calc.set_num1(num1));
		do
		{
			cout << "Введите num2: ";
			cin >> num2;
			if (!calc.set_num2(num2))
			{
				cout << "Некорректный ввод!" << endl;
			}

		} while (!calc.set_num2(num2));
		cout << "num1 + num2 = " << calc.add() << endl;
		cout << "num1 - num2 = " << calc.subtract_2_1() << endl;
		cout << "num2 - num1 = " << calc.subtract_1_2() << endl;
		cout << "num1 * num2 = " << calc.multiply() << endl;
		cout << "num1 / num2 = " << calc.divide_1_2() << endl;
		cout << "num2 / num1 = " << calc.divide_2_1() << endl;
	}
	return 0;
}