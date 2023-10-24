#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Counter
{
private:
	int num;
public:
	Counter();
	~Counter();
	Counter(int num);
	void increase_count()
	{
		this->num++;
	}
	void decrase_count()
	{
		this->num--;
	}
	int get_count()
	{
		return this->num;
	}

};

Counter::Counter()
{
	this->num = 1;
}

Counter::Counter(int num)
{
	this->num = num;
}
Counter::~Counter(){}


int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int start_val;
	Counter* val;
	string str;
	string answer;
	cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	cin >> answer;
	if (answer == "да")
	{
		cout << "Введите начальное значение счётчика: ";
		cin >> start_val;
		val = new Counter(start_val);

	}
	else if (answer == "нет")
	{
		val = new Counter();
	}
	else
	{
		cout << endl << "Неправильный ввод, использовано значение по умолчанию - 1";
		val = new Counter();
	}

	while(true)
	{
		cout << "Введите команду ('+', '-', '=' или 'x'): ";
		cin >> str;
		if (str == "+")
		{
			val->increase_count();
		}
		else if (str == "-")
		{
			val->decrase_count();
		}
		else if (str == "=")
		{
			cout << val->get_count() << endl;
		}
		else if (str == "x" || str == "х")
		{
			cout << "До свидания!" << endl;
			break;
		}
		else
		{
			cout << "Неправильная комманда, введите еще раз." << endl;
			continue;
		}		
	}
	delete val;
	return 0;
}