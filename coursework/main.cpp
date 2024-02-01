#include <iostream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <locale> 
#include "lib/tv.h"
#include "lib/ground_tv.h"
#include "lib/air_tv.h"
#include "lib/boots.h"
#include "lib/broom.h"
#include "lib/camel.h"
#include "lib/camel_fast.h"
#include "lib/carpet.h"
#include "lib/centaur.h"
#include "lib/eagle.h"
#include <cstdlib>

using namespace std;
bool repeat_race = true;
void print_reg_start_race(vector<Vehicle*>& tv, int distance, int type_race);

// "Стартуем гонку". Производим расчеты и выводим на экран
void start_race(vector<Vehicle*>& tv, int distance)
{
	int counter = 1;
	int in_val;
	// сортировОчка вектора
	for (auto i = 1; i < tv.size(); i++)
	{
		for (auto j = 0; j < tv.size() - i; j++) 
		{
			if (tv[j]->calc(distance) > tv[j + 1]->calc(distance)) 
			{
				auto tmp = tv[j];
				tv[j] = tv[j + 1];
				tv[j + 1] = tmp;
			}
		}
	}

	wcout << L"Результаты гонки:" << endl;
	for (auto i = 0; i < tv.size(); i++)
	{
		wcout << counter << L". " << tv[i]->get_name() << L". Время: " << tv[i]->calc(distance) << endl;
		counter++;
	}
	wcout << endl;
	wcout << L"1.  Провести еще одну гонку" << endl;
	wcout << L"2.  Выйти" << endl;
	wcout << L"Выберите действие: ";
	cin >> in_val;
	if (in_val == 1)
	{
		repeat_race = true;
	}
	else if (in_val == 2)
	{
		repeat_race = false;
	}
	else
	{
		wcout << L"Вы ввели не корректно значение, проидите гонку еще раз))" << endl;
	}
	system("cls");
}

//добавляем необходимый класс в вектор
void create_tv(vector<Vehicle*>& tv, wstring name)
{
	if (name == L"Ботинки-вездеходы")
	{
		tv.push_back(new Boots());
		wcout << name << L" успешно зарегистрирован" << endl;

	}
	else if (name == L"Метла")
	{
		tv.push_back(new Broom());
		wcout << name << L" успешно зарегистрирован" << endl;

	}
	else if (name == L"Верблюд")
	{
		tv.push_back(new Camel());
		wcout << name << L" успешно зарегистрирован" << endl;

	}
	else if (name == L"Кентавр")
	{
		tv.push_back(new Centaur());
		wcout << name << L" успешно зарегистрирован" << endl;

	}
	else if (name == L"Орел")
	{
		tv.push_back(new Eagle());
		wcout << name << L" успешно зарегистрирован" << endl;

	}
	else if (name == L"Верблюд-быстроход")
	{
		tv.push_back(new CamelFast());
		wcout << name << L" успешно зарегистрирован" << endl;

	}
	else if (name == L"Ковер-самолет")
	{
		tv.push_back(new Carpet());
		wcout << name << L" успешно зарегистрирован" << endl;

	}

}

//  Проверяем правильно ли введен тип гонки, у нас их может быть только три.
bool check_type(int type)
{
	if (type < 0 || type > 3)
	{
		return false;
	}
	else
	{
		return true;
	}

}

// проверим не зарегистрировано ли уже ТС
bool check_reg_tv(vector<Vehicle*>& tv, wstring name)
{
	if (tv.size() > 0)
	{
		for (auto i = 0; i < tv.size(); i++)
		{
			if (tv[i]->get_name() == name)
			{
				return true;
			}
		}
	}
	return false;
}


//Проверим ввод значения в поле регистрация
bool check_choce_start(int in_val)
{
	if (in_val == 1 || in_val == 2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// формируем список транспортных средств
wstring str_list_tv(vector<Vehicle*>& tv)
{
	wstring tmp;
	for (auto i = 0; i < tv.size(); i++)
	{
		if (i < tv.size() - 1) 
		{
			tmp += tv[i]->get_name() + L", ";
		}
		else
		{
			tmp += tv[i]->get_name();
		}
		
	}
	return tmp;

}

// предоставляем выбор регистрации ТС
void pring_reg_tv(vector<Vehicle*>& tv, int distance, int type_race)
{
	wstring type;
	int in_tv;
	if (type_race == 1)
	{
		type = (L"наземного транспорта.");
	}
	else if (type_race == 2)
	{
		type = (L"воздушного транспорта.");
	}
	else if (type_race == 3)
	{
		type = (L"наземного и воздушного транспорта.");
	}
	wcout << L"Гонка для " << type << L"Расстояние: " << distance << endl;
	if (tv.size() != 0)
	{
		wcout << L"Зарегистрированные транспортные средства: " << str_list_tv(tv) << endl;
	}
	wcout << L"1.  Ботинки-вездеходы" << endl;
	wcout << L"2.  Метла" << endl;
	wcout << L"3.  Верблюд" << endl;
	wcout << L"4.  Кентавр" << endl;
	wcout << L"5.  Орел" << endl;
	wcout << L"6.  Верблюд-быстроход" << endl;
	wcout << L"7.  Ковер-самолет" << endl;
	wcout << L"0.  Закончить регистрацию" << endl;
	wcout << L"Выбирете странспорт или 0 для окончания процесса регистрации: ";
	cin >> in_tv;
	system("cls");
	//переведем значения в строковую переменную name
	wstring name = (L"Транспорт");
	switch (in_tv)
	{
	case 1: name = (L"Ботинки-вездеходы"); break;
	case 2: name = (L"Метла"); break;
	case 3: name = (L"Верблюд"); break;
	case 4: name = (L"Кентавр"); break;
	case 5: name = (L"Орел"); break;
	case 6: name = (L"Верблюд-быстроход"); break;
	case 7: name = (L"Ковер-самолет"); break;
	default:
		break;
	}
	if (in_tv == 0)
	{
		print_reg_start_race(tv, distance, type_race);
	}
	else
	{
		if (type_race == 1)
		{
			if (in_tv == 1 || in_tv == 3 || in_tv == 4 || in_tv == 6)
			{
				if (check_reg_tv(tv, name))
				{
					wcout << name << L" уже зарегистрирован!";
					pring_reg_tv(tv, distance, type_race);
				}
				else
				{
					create_tv(tv, name);
					pring_reg_tv(tv, distance, type_race);
				}
			}
			else if (in_tv == 2 || in_tv == 5 || in_tv == 7)
			{
				wcout << L"Попытка зарегистрировать неправильный тип транспортного средства!";
				pring_reg_tv(tv, distance, type_race);
			}
			else
			{
				wcout << L"Некорректное значение";
				pring_reg_tv(tv, distance, type_race);
			}
		}
		else if (type_race == 2)
		{
			if (in_tv == 2 || in_tv == 5 || in_tv == 7)
			{
				if (check_reg_tv(tv, name))
				{
					wcout << name << L" уже зарегистрирован!";
					pring_reg_tv(tv, distance, type_race);
				}
				else
				{
					create_tv(tv, name);
					pring_reg_tv(tv, distance, type_race);
				}
			}
			else if (in_tv == 1 || in_tv == 3 || in_tv == 4 || in_tv == 6)
			{
				wcout << L"Попытка зарегистрировать неправильный тип транспортного средства!";
				pring_reg_tv(tv, distance, type_race);
			}
			else
			{
				wcout << L"Некорректное значение";
				pring_reg_tv(tv, distance, type_race);
			}

		}
		else
		{
			if (check_reg_tv(tv, name))
			{
				wcout << name << L" уже зарегистрирован!";
				pring_reg_tv(tv, distance, type_race);
			}
			else
			{
				create_tv(tv, name);
				pring_reg_tv(tv, distance, type_race);
			}
		}
	}

}

// Выбыраем зарегистрировать ТС или начать гонку
void print_reg_start_race(vector<Vehicle*>& tv, int distance, int type_race)
{
	int in_val;
	// проверяем количество зарегистрированных транспортных средств
	if (tv.size() == 0 || tv.size() == 1)
	{
		wcout << L"Должно быть зарегистрировано хотя бы 2 транспортных средства!" << endl;
		wcout << L"1.  Зарегистрировать транспорт" << endl;
		wcout << L"Выберите действие: ";
	}
	else if (tv.size() >= 2)
	{
		wcout << L"1.  Зарегистрировать транспорт" << endl;
		wcout << L"2.  Начать гонку" << endl;
		wcout << L"Выберите действие: ";
	}
	cin >> in_val;
	system("cls");
	if (check_choce_start(in_val))
	{
		if (in_val == 1)
		{
			pring_reg_tv(tv, distance, type_race);
		}
		else
		{
			start_race(tv, distance);
		}
	}
	else
	{
		wcout << L"Некорректное значение, попробуйте еще раз!" << endl;
		print_reg_start_race(tv, distance, type_race);
	}
}

//Функция выбора типа гонки, возвращает выбранный тип
int print_type_race()
{
	int type = 0;
	wcout << L"1.  Гонка для наземного транспорта" << endl;
	wcout << L"2.  Гонка для воздушного транспорта" << endl;
	wcout << L"3.  Гонка для наземного и воздушного транспорта" << endl;
	wcout << L"Выбирете тип гонки: ";
	cin >> type;
	// Сделаем проверку правильности введенного значения. Рекурсия
	system("cls");
	if (check_type(type))
	{
		return type;
	}
	else
	{
		wcout << L"Вы ввели не корректное значение, попробуйте снова!" << endl;
		print_type_race();
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	// Приветствие
	wcout << L"Добро пожаловать в гоночный симулятор!" << endl;

	//определяем переменные
	int distance = 0;		// переменная для расстояния которое будет указано пользователем
	int type_race = 0;		// тип гонки заданные пользователем
	do
	{
		type_race = print_type_race();		// делаем вывод на экран с типами гонки
		wcout << L"Укажите длину дистанции (должна быть положительна): ";
		cin >> distance;
		vector<Vehicle*> arr; // создаем массив транспортных средст
		system("cls");
		print_reg_start_race(arr, distance, type_race);
	} while (repeat_race);
}