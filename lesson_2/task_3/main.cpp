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
	cout << "�����: " << address.city << endl;
	cout << "�����: " << address.street << endl;
	cout << "����� ����: " << address.number_house << endl;
	cout << "����� ��������: " << address.room_apartament << endl;
	cout << "������: " << address.index << endl;
};

int main () 
{
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	addresses address, address2;
	cout << "�����: ";
	cin >> address.city;
	cout << "�����: ";
	cin >> address.street;
	cout << "����� ����: ";
	cin >> address.number_house;
	cout << "����� ��������: ";
	cin >> address.room_apartament;
	cout << "������: ";
	cin >> address.index;
	cout << "\n";
	cout << "�����: ";
	cin >> address2.city;
	cout << "�����: ";
	cin >> address2.street;
	cout << "����� ����: ";
	cin >> address2.number_house;
	cout << "����� ��������: ";
	cin >> address2.room_apartament;
	cout << "������: ";
	cin >> address2.index;
	print_address(address);
	print_address(address2);
	return 0;
}