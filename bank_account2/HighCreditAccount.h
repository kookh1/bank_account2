#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

/*�ſ�ŷ� �������� Ŭ����*/
class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;  //�߰� ������
public:
	HighCreditAccount(int accId, int balance, char *name, int ratio, int special)
		: NormalAccount(accId, balance, name, ratio), specialRatio(special)
	{}

	virtual void ShowAccount() const  //�������� ���
	{
		NormalAccount::ShowAccount();
		char creditLevel;
		switch (specialRatio)   //�߰� ���� -> �ſ���
		{
		case 7:
			creditLevel = 'A';
			break;
		case 4:
			creditLevel = 'B';
			break;
		case 2:
			creditLevel = 'C';
			break;
		}
		cout << "�ſ���(1toA, 2toB, 3toC): " << creditLevel << endl << endl;
	}

	virtual void SetMoney(int money)   //�Ա�
	{
		Account::SetMoney(money + money*(GetRatio() + specialRatio)*0.01);
		//�Ա� + (�Ա� * (������+�߰�������))
	}
};

#endif