#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

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

	virtual void SetMoney(int money)   //�Ա�
	{
		Account::SetMoney(money + money*interestRatio*0.01);
		//�Ա� + (�Ա� * ������)
	}
};

#endif