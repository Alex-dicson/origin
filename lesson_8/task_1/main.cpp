#include <iostream>
#include <Windows.h>

using namespace std;

int function(std::string str, int forbidden_length)
{
	if (str.length() != forbidden_length)
	{
		return str.length();
	}
	throw "Вы ввели слово запретной длины! До свидания";


}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "Russian");
	string in_str;
	int len;
	cout << "Введите запретную длину: ";
	cin >> len;
	while (true)
	{
		cout << "Введите слово: ";
		cin >> in_str;
		try
		{
			function(in_str, len);
			cout << "Длина слова " << "\"" << in_str << "\" " <<  "равна " << function(in_str, len) << endl;
			continue;
		}
		catch(const char* err)
		{
			cout << err << endl;
			break;
		}
	}

}