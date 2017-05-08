#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "BankingCommonDecl.h"
#include "String.h"

/*고객 계좌정보 클래스*/
class Account
{
private:
	int accId;   //계좌번호
	int balance; //잔액
	String name; //이름

public:
	Account(int accId, int balance, String name);
	
	int GetAccId() const;     //계좌ID 반환
	int GetMoney(int money);  //출금
	virtual void SetMoney(int money) = 0; //입금
	virtual void ShowAccount() const = 0;   //계좌정보 출력
};

#endif
