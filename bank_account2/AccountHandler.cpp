#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

//empty
AccountHandler::AccountHandler()
{}

//계좌정보 해제
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}


//메뉴 출력
void AccountHandler::ShowMenu()
{
	cout << "------Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
	cout << "선택: ";
}


//계좌 만들기
void AccountHandler::MakeAccount()
{
	cout << endl << "[계좌종류선택]" << endl;
	cout << "1.보통예금계좌 2.신용신뢰계좌" << endl;
	int sel;
	cout << "선택: ";
	cin >> sel;

	switch (sel)
	{
	case NORMAL:
		MakeNormalAccount();
		break;

	case CREDIT:
		MakeCreditAccount();
		break;
	}

}

//보통계좌 만들기
void AccountHandler::MakeNormalAccount()
{
	int accID;
	cout << "계좌ID: ";
	cin >> accID;

	char name[NAME_LEN];
	cout << "이름: ";
	cin >> name;

	int money;
	cout << "입금액: ";
	cin >> money;

	int ratio;
	cout << "이자율: ";
	cin >> ratio;

	accArr[accNum++] = new NormalAccount(accID, money, name, ratio);
	cout << "보통계좌가 개설되었습니다." << endl;
}

//신용신뢰계좌 만들기
void AccountHandler::MakeCreditAccount()
{
	int accID;
	cout << "계좌ID: ";
	cin >> accID;

	char name[NAME_LEN];
	cout << "이름: ";
	cin >> name;

	int money;
	cout << "입금액: ";
	cin >> money;

	int ratio;
	cout << "이자율: ";
	cin >> ratio;

	int special;
	cout << "신용등급(1toA, 2toB, 3toC): ";
	cin >> special;

	switch (special)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(accID, money, name, ratio, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCreditAccount(accID, money, name, ratio, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCreditAccount(accID, money, name, ratio, LEVEL_C);
		break;
	}
	cout << "신용신뢰계좌가 개설되었습니다." << endl;
}

//입금
void AccountHandler::Deposit()
{
	cout << endl << "[입 금]" << endl;

	int accID;   //계좌ID
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accID)
		{
			int money;  //입금액
			cout << "입금액: ";
			cin >> money;
			accArr[i]->SetMoney(money);
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "해당 계좌ID가 존재하지 않습니다." << endl;
}


//출금
void AccountHandler::Withdraw()
{
	cout << endl << "[출 금]" << endl;

	int accID;   //계좌ID
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accID)
		{
			int money;  //출금액
			cout << "출금액: ";
			cin >> money;
			accArr[i]->GetMoney(money);
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "해당 계좌ID가 존재하지 않습니다." << endl;
}


//모든 계좌 출력
void AccountHandler::ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << endl << "[NUM : " << i + 1 << " ]" << endl;
		accArr[i]->ShowAccount();
	}
}
