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
		cout << "�ſ���(1toA, 2toB, 3toC): " << specialRatio << endl << endl;
	}

	virtual void SetMoney(int money)   //�Ա�
	{
		Account::SetMoney(money + money*(GetRatio() + specialRatio)*0.01);
		//�Ա� + (�Ա� * (������+�߰�������))
	}
};

#endif