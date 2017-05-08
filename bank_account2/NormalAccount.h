#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"

/*보통계좌정보 클래스*/
class NormalAccount : public Account
{
private:
	int interestRatio;  //이자율
public:
	NormalAccount(int accId, int balance, String name, int ratio)
		: Account(accId, balance, name), interestRatio(ratio)
	{}
	int GetRatio() const  //이자율 가져오기
	{
		return interestRatio;
	}
	virtual void ShowAccount() const  //계좌정보 출력
	{
		Account::ShowAccount();
		cout << "이자율: " << interestRatio << endl;
	}

	virtual void SetMoney(int money)   //입금
	{
		Account::SetMoney(money + money*interestRatio*0.01);
		//입금 + (입금 * 이자율)
	}
};

#endif