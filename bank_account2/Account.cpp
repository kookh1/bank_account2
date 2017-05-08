#include "Account.h"
#include "ExceptionHandler.h"

Account::Account(int accId, int balance, String name)
	: accId(accId), balance(balance)
{
	this->name = name;
}

int Account::GetAccId() const  //����ID ��ȯ
{
	return accId;
}

int Account::GetMoney(int money) throw (WithdrawException)  //���
{
	if (this->balance < money)
	{
		WithdrawException extp(money - (this->balance));
		throw extp;
	}
	this->balance -= money;
	return balance;
}

void Account::SetMoney(int money)  //�Ա�
{
	this->balance += money;
}

void Account::ShowAccount() const  //�������� ���
{
	cout << "����ID: " << accId << endl;
	cout << "�̸�: " << name << endl;
	cout << "�Աݾ�: " << balance << endl;
}

