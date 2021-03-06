#include "Account.h"
#include "ExceptionHandler.h"

Account::Account(int accId, int balance, String name)
	: accId(accId), balance(balance)
{
	this->name = name;
}

int Account::GetAccId() const  //계좌ID 반환
{
	return accId;
}

int Account::GetMoney(int money) throw (WithdrawException)  //출금
{
	if (this->balance < money)
	{
		WithdrawException extp(money - (this->balance));
		throw extp;
	}
	
	if (money < 0)
	{
		DepositException extp(money);
		throw extp;
	}
	this->balance -= money;
	return balance;
}

void Account::SetMoney(int money)  //입금
{
	this->balance += money;
}

void Account::ShowAccount() const  //계좌정보 출력
{
	cout << "계좌ID: " << accId << endl;
	cout << "이름: " << name << endl;
	cout << "입금액: " << balance << endl;
}

