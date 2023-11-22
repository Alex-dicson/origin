#include <iostream>
#include "greeter.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string first_name;
	std::cout << "Введите имя: ";
	std::cin >> first_name;
	Greeter pr_name;
	pr_name.greet(first_name);
	return 0;
}