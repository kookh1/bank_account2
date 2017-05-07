#include "Account.h"
#include "AccountHandler.h"


int main()
{
	AccountHandler ac;
	while (1)
	{
		ac.ShowMenu();   //메뉴출력
		int sel;
		cin >> sel;

		switch (sel)
		{
		case MAKE:
			ac.MakeAccount();  //계좌만들기
			break;
		case DEPOSIT:
			ac.Deposit();     //입금하기
			break;
		case WITHDRAW:
			ac.Withdraw();    //출금하기
			break;
		case SHOW:
			ac.ShowAllAccount();  //모든계좌출력
			break;
		case EXIT:
			cout << "프로그램을 종료합니다." << endl;
			return 0;
		default:
			cout << "잘못된 입력입니다." << endl;
		}
		cout << endl;
	}

	return 0;
}

