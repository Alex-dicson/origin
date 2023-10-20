#include <iostream>
using namespace std;

enum months
{
	january = 1,
	february,
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november,
	december,

};

int main()
{
	setlocale(LC_ALL, "Russian");
	months month = january;
	int number = month;
	while (static_cast<int>(number) > 0 && static_cast<int>(number) < 13) {
		cout << "Введите номер месяца: ";
		cin >> number;
		switch (number)
		{
		case january:
			cout << "Январь\n";
			break;
		case february:
			cout << "Февраль\n";
			break;
		case march:
			cout << "Март\n";
			break;
		case april:
			cout << "Апрель\n";
			break;
		case may:
			cout << "Май\n";
			break;
		case june:
			cout << "Июнь\n";
			break;
		case july:
			cout << "Июль\n";
			break;
		case august:
			cout << "Август\n";
			break;
		case september:
			cout << "Сентябрь\n";
			break;
		case october:
			cout << "Октябрь\n";
			break;
		case november:
			cout << "Ноябрь\n";
			break;
		case december:
			cout << "Декабрь\n";
			break;
		case 0:
			cout << "До свидания\n";
			break;
		default:
			cout << "Неправильный номер!\n";
			break;
		}

	}
	return 0;

};