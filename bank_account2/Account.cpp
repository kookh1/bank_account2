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

int Account::GetAccId() const  //����ID ��ȯ
{
	return accId;
}

int Account::GetMoney(int money)  //���
{
	this->balance -= money;
	return balance;
}

void Account::SetMoney(int money) //�Ա�
{
	this->balance += money;
}

void Account::ShowAccount() const  //�������� ���
{
	cout << "����ID: " << accId << endl;
	cout << "�̸�: " << name << endl;
	cout << "�Աݾ�: " << balance << endl;
}

