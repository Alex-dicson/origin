#include <iostream>
#include <string>
#include <fstream>

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

int main()
{
	setlocale(LC_ALL, "Russian");
	int fields, quantity_address;
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
	fin >> quantity_address;
	Address* addr = new Address[quantity_address];
	for(int i = 0; i < quantity_address; i++)
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

	fout << to_string(quantity_address) << endl;
	for (int i = 0; i < quantity_address; i++)
	{
		fout << addr[i].get_output_address() << endl;
	}
	fout.close();
	delete[] addr;
	return 0;

}