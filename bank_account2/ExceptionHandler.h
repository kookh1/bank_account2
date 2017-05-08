#ifndef __EXCEPTION_HANDLER_H__
#define __EXCEPTION_HANDLER_H__

#include <iostream>
using namespace std;

class DepositException
{
private:
	int reqDep;		// ��û �Աݾ�
public:
	DepositException(int money) : reqDep(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: " << reqDep << "�� �ԱݺҰ�]" << endl;
	}
};

class WithdrawException
{
private:
	int	balance;	// �ܰ�
public:
	WithdrawException(int money) : balance(money)
	{ }
	void ShowExceptionReason()
	{
		cout << "[���� �޽���: �ܾ� " << balance << ", �ܾ׺���]" << endl;
	}
};

#endif