#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "ExceptionHandler.h"

/*����������� Ŭ����*/
class NormalAccount : public Account
{
private:
	int interestRatio;  //������
public:
	NormalAccount(int accId, int balance, String name, int ratio)
		: Account(accId, balance, name), interestRatio(ratio)
	{}
	int GetRatio() const  //������ ��������
	{
		return interestRatio;
	}
	virtual void ShowAccount() const  //�������� ���
	{
		Account::ShowAccount();
		cout << "������: " << interestRatio << endl;
	}

	virtual void SetMoney(int money) throw (DepositException)  //�Ա�
	{
		if (money < 0)
		{
			DepositException expt(money);
			throw expt;
		}
		Account::SetMoney(money + int(money*interestRatio*0.01));
		//�Ա� + (�Ա� * ������)
	}
};

#endif