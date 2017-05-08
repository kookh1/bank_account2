#include "Account.h"

Account::Account(int accId, int balance, char *name)
	: accId(accId), balance(balance)
{
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Account::Account(const Account& ref)
	:accId(ref.accId), balance(ref.balance)
{
	this->name = new char[strlen(ref.name) + 1];
	strcpy(this->name, ref.name);
}

Account& Account::operator=(const Account& ref)
{
	this->accId = ref.accId;
	this->balance = ref.balance;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, ref.name);

	return *this;
}


Account::~Account()
{
	delete[] name;
}

int Account::GetAccId() const  //계좌ID 반환
{
	return accId;
}

int Account::GetMoney(int money)  //출금
{
	this->balance -= money;
	return balance;
}

void Account::SetMoney(int money) //입금
{
	this->balance += money;
}

void Account::ShowAccount() const  //계좌정보 출력
{
	cout << "계좌ID: " << accId << endl;
	cout << "이름: " << name << endl;
	cout << "입금액: " << balance << endl;
}

