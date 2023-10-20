#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct addresses
{
	string city;
	string street;
	int number_house;
	int room_apartament;
	int index;
};

void print_address (addresses& address)
{
	cout << endl;
	cout << "Город: " << address.city << endl;
	cout << "Улица: " << address.street << endl;
	cout << "Номер дома: " << address.number_house << endl;
	cout << "Номер квартиры: " << address.room_apartament << endl;
	cout << "Индекс: " << address.index << endl;
};

int main () 
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	addresses address, address2;
	cout << "Город: ";
	cin >> address.city;
	cout << "Улица: ";
	cin >> address.street;
	cout << "Номер дома: ";
	cin >> address.number_house;
	cout << "Номер квартиры: ";
	cin >> address.room_apartament;
	cout << "Индекс: ";
	cin >> address.index;
	cout << "\n";
	cout << "Город: ";
	cin >> address2.city;
	cout << "Улица: ";
	cin >> address2.street;
	cout << "Номер дома: ";
	cin >> address2.number_house;
	cout << "Номер квартиры: ";
	cin >> address2.room_apartament;
	cout << "Индекс: ";
	cin >> address2.index;
	print_address(address);
	print_address(address2);
	return 0;
}