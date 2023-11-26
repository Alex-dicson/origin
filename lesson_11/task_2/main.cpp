#include <iostream>
#include "lib/leaver.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string first_name;
	std::cout << "Введите имя: ";
	std::cin >> first_name;
	Leaver l;
	l.leave(first_name);
}