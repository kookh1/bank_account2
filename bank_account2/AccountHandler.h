#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

/*계좌정보 처리 클래스*/
class AccountHandler
{
private:
	BoundCheckAccountPtrArray accArr;  //고객 계좌정보 저장 포인터 객체 배열
	int accNum = 0;                //계좌 개수

public:
	/*은행 계좌 관리 기능*/
	AccountHandler();      //empty
	~AccountHandler();     //계좌정보 해제
	void ShowMenu();       //메뉴 출력
	void MakeAccount();    //계좌 만들기
	void Deposit();        //입금
	void Withdraw();       //출금
	void ShowAllAccount(); //모든 계좌 출력

	void MakeNormalAccount();  //보통계좌 만들기
	void MakeCreditAccount();  //신용신뢰계좌 만들기
};

#endif