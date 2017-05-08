#ifndef __HIGH_CREDIT_ACCOUNT_H__
#define __HIGH_CREDIT_ACCOUNT_H__

#include "NormalAccount.h"

/*신용신뢰 계좌정보 클래스*/
class HighCreditAccount : public NormalAccount
{
private:
	int specialRatio;  //추가 이자율
public:
	HighCreditAccount(int accId, int balance, char *name, int ratio, int special)
		: NormalAccount(accId, balance, name, ratio), specialRatio(special)
	{}

	virtual void ShowAccount() const  //계좌정보 출력
	{
		NormalAccount::ShowAccount();
		char creditLevel;
		switch (specialRatio)   //추가 이율 -> 신용등급
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
		cout << "신용등급(1toA, 2toB, 3toC): " << creditLevel << endl << endl;
	}

	virtual void SetMoney(int money)   //입금
	{
		Account::SetMoney(money + money*(GetRatio() + specialRatio)*0.01);
		//입금 + (입금 * (이자율+추가이자율))
	}
};

#endif