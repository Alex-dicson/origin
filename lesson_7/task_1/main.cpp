#include <iostream>

#define MODE 1
#ifndef MODE
#error Константа MODE не определена, необходимо определить ее! 
#endif // !MODE
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a, b;
#if MODE == 1
	cout << "Работаю в боевом режиме" << endl;
	cout << "Введите число 1: ";
	cin >> a;
	cout << "Введите число 2: ";
	cin >> b;
	cout << "Результат сложения: " << add(a, b) << endl;
#elif MODE == 0
	cout << "Работаю в режиме тренировки" << endl;
#else
	cout << "Неизвестный режим. Завершение работы" << endl;
#endif
	return 0;
}

