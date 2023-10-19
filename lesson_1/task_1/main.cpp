#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void change_arr_1(int* arr, int& elements)
{
	int tmp;
	for (int i = 0; i < elements; i++ )
	{
		if (i == 0)
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
		}
		else if (i == elements - 1)
		{
			arr[i] = tmp;
		}
		else
		{
			arr[i] = arr[i + 1];
		}
	}

}
void change_arr_2(int* arr, int& elements)
{
	int tmp;
	for (int i = elements -1; i >= 0; i--)
	{
		if (i == elements -1)
		{
			tmp = arr[i];
			arr[i] = arr[i - 1];
		}
		else if (i == 0)
		{
			arr[i] = tmp;
		}
		else
		{
			arr[i] = arr[i - 1];
		}
	}
}

void reading_file(ifstream& fin, int& elements, int* arr)
{
	string str;
	for (int i = 0; i < elements; i++)
	{
		fin >> str;
		arr[i] = stoi(str);
	}

}
int main()
{
	string str;
	int elements_1, elements_2;

	ifstream fin("in.txt");
	if (!fin)
	{
		cout << "No file!" << endl;
		return -1;
	}
	fin >> str;
	elements_1 = stoi(str);
	int* arr_1 = new int[elements_1];
	reading_file(fin, elements_1, arr_1);
	fin >> str;
	elements_2 = stoi(str);
	int* arr_2 = new int[elements_2];
	reading_file(fin, elements_2, arr_2);
	fin.close();
	change_arr_1(arr_1, elements_1);
	change_arr_2(arr_2, elements_2);
	ofstream fout("out.txt");
	if (!fout)
	{
		cout << "No file!" << endl;
		return -1;
	}
	fout << elements_2 << endl;
	for (int i = 0; i < elements_2; i++)
	{
		fout << arr_2[i] << " ";
	}
	fout << endl;
	fout << elements_1 << endl;
	for (int i = 0; i < elements_1; i++)
	{
		fout << arr_1[i] << " ";
	}
	fout.close();
	delete[] arr_1;
	delete[] arr_2;
	return 0;
}