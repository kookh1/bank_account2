#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "ExceptionHandler.h"

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

	virtual void SetMoney(int money) throw (DepositException)  //입금
	{
		if (money < 0)
		{
			DepositException expt(money);
			throw expt;
		}
		Account::SetMoney(money + int(money*interestRatio*0.01));
		//입금 + (입금 * 이자율)
	}
};

#endif