#include <iostream>
#include <string>
#include <cstdlib>  

using namespace std;

struct bank_accounts
{
	int account_number;
	string name;
	int balance;
};

void change_balance(bank_accounts& account, int new_balance)
{
	account.balance = new_balance;
	cout << "��� ����: " << account.account_number << ", " << account.name << ", " << account.balance;
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	bank_accounts account;
	string name;
	int number, balance, new_balance;
	cout << "������� ����� �����: ";
	cin >> number;
	cout << "������� ��� ���������: ";
	cin >> name;
	cout << "������� ������: ";
	cin >> balance;
	account = { number, name, balance };
	cout << "������� ����� ������: ";
	cin >> new_balance;
	change_balance(account, new_balance);
	return 0;

}
