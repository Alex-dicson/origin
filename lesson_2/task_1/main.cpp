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
		cout << "������� ����� ������: ";
		cin >> number;
		switch (number)
		{
		case january:
			cout << "������\n";
			break;
		case february:
			cout << "�������\n";
			break;
		case march:
			cout << "����\n";
			break;
		case april:
			cout << "������\n";
			break;
		case may:
			cout << "���\n";
			break;
		case june:
			cout << "����\n";
			break;
		case july:
			cout << "����\n";
			break;
		case august:
			cout << "������\n";
			break;
		case september:
			cout << "��������\n";
			break;
		case october:
			cout << "�������\n";
			break;
		case november:
			cout << "������\n";
			break;
		case december:
			cout << "�������\n";
			break;
		case 0:
			cout << "�� ��������\n";
			break;
		default:
			cout << "������������ �����!\n";
			break;
		}

	}
	return 0;

};