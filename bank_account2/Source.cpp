#include<iostream>
using namespace std;


/* constant 정보 */
enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT};

/*고객 정보 관련 데이터*/
struct Account  
{
	int accId;   //계좌번호
	int balance; //잔액
	char name[20];  //이름
};

struct Account accArr[100];  //고객 정보 저장 배열
int accNum = 0;              //계좌 개수



/*은행 계좌 관리 기능*/
void ShowMenu();       //메뉴 출력
void MakeAccount();    //계좌 만들기
void Deposit();        //입금
void Withdraw();       //출금
void ShowAllAccount(); //모든 계좌 출력


//메뉴 출력
void ShowMenu()
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
void MakeAccount()
{
	cout << endl << "[계좌개설]" << endl;

	Account myAcc;
	int accID;
	cout << "계좌ID: ";
	cin >> myAcc.accId;

	cout << "이름: ";
	cin >> myAcc.name;

	cout << "입금액: ";
	cin >> myAcc.balance;

	accArr[accNum++] = myAcc;  //계좌 1개를 만들어서 계좌 저장소에 저장
	cout << "계좌가 개설되었습니다." << endl;
}


//입금
void Deposit()
{
	cout << endl<<"[입 금]" << endl;
	
	int accID;   //계좌ID
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accId == accID)
		{
			int money;  //입금액
			cout << "입금액: ";
			cin >> money;
			accArr[i].balance += money;
			cout << "입금완료" << endl;
			return;
		}
	}
	cout << "해당 계좌ID가 존재하지 않습니다." << endl;
}


//출금
void Withdraw()
{
	cout << endl << "[출 금]" << endl;

	int accID;   //계좌ID
	cout << "계좌ID: ";
	cin >> accID;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accId == accID)
		{
			int money;  //출금액
			cout << "출금액: ";
			cin >> money;
			accArr[i].balance -= money;
			cout << "출금완료" << endl;
			return;
		}
	}
	cout << "해당 계좌ID가 존재하지 않습니다." << endl;
}


//모든 계좌 출력
void ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << endl<<"[NUM : " << i + 1 <<" ]"<< endl;
		cout << "계좌ID: " << accArr[i].accId << endl;
		cout << "이름: " << accArr[i].name << endl;
		cout << "입금액: " << accArr[i].balance << endl<<endl;
	}
}



int main()
{

	while (1)
	{
		ShowMenu();   //메뉴출력
		int sel;
		cin >> sel;

		switch (sel)
		{
		case MAKE:
			MakeAccount();  //계좌만들기
			break;
		case DEPOSIT:
			Deposit();     //입금하기
			break;
		case WITHDRAW:
			Withdraw();    //출금하기
			break;
		case SHOW:
			ShowAllAccount();  //모든계좌출력
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

