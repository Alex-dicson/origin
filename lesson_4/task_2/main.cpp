#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

using namespace std;

class Address
{
private:
	string city;
	string street;
	int house;
	int apartment;
public:
	Address()
	{
		city = "Москва";
		street = "Гагарина";
		house = 1;
		apartment = 1;

	};
	void set_parametr(string city, string street, int house, int apartament)
	{
		this->city = city;
		this->street = street;
		this->house = house;
		this->apartment = apartament;
	}
	string get_output_address()
	{
		return city + ", " + street + ", " + to_string(house) + ", " + to_string(apartment);
	}
};

void sort(Address* addresses, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (addresses[j].get_output_address() > addresses[j + 1].get_output_address())
			{
				Address b = addresses[j];
				addresses[j] = addresses[j + 1];
				addresses[j + 1] = b;
			}
		}
	}

}

int main()
{
	setlocale(LC_ALL, "Russian");
	int quantity_addresses;
	string city;
	string street;
	int house;
	int apartment;
	ifstream fin("in.txt");
	if (!fin)
	{
		cout << "No file!" << endl;
		return -1;
	}
	fin >> quantity_addresses;
	Address* addr = new Address[quantity_addresses];
	for (int i = 0; i < quantity_addresses; i++)
	{
		fin >> city;
		fin >> street;
		fin >> house;
		fin >> apartment;
		addr[i].set_parametr(city, street, house, apartment);
	}
	fin.close();

	ofstream fout("out.txt");
	if (!fout)
	{
		cout << "No file!" << endl;
		return -1;
	}

	fout << to_string(quantity_addresses) << endl;
	sort(addr, quantity_addresses);
	for (int i = 0; i < quantity_addresses; i++)
	{
		fout << addr[i].get_output_address() << endl;
	}
	fout.close();
	delete[] addr;
	return 0;

}