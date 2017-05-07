#include<iostream>
#include<cstring>
using namespace std;


/* constant 정보 */
enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT};  //메뉴 선택
enum{NORMAL=1, CREDIT};   //계좌종류 선택

const int NAME_LEN = 20;     //이름 길이
const int ACCOUNT_LEN = 100; //계좌 개수


/*고객 계좌정보 클래스*/
class Account  
{
private:     
	int accId;   //계좌번호
	int balance; //잔액
	char *name;  //이름

public:
	Account(int accId, int balance, char *name);  
	Account(const Account& ref);  
	~Account();  

	int GetAccId() const;     //계좌ID 반환
	int GetMoney(int money);  //출금
	virtual void SetMoney(int money) = 0; //입금
	virtual void ShowAccount() const=0;   //계좌정보 출력
};

/*보통계좌정보 클래스*/
class NormalAccount : public Account
{
private:
	int interestRatio;  //이자율
public:
	NormalAccount(int accId, int balance, char *name, int ratio) 
		: Account(accId, balance, name), interestRatio(ratio)
	{}
	
	virtual void ShowAccount() const  //계좌정보 출력
	{
		Account::ShowAccount();
		cout << "이자율: " << interestRatio << endl;	
	}

	virtual void SetMoney(int money)   //입금
	{
		Account::SetMoney(money+ money*interestRatio*0.01);
		//입금 + (입금 * 이자율)
	}
};

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
		cout << "신용등급(1toA, 2toB, 3toC): " << specialRatio << endl << endl;
	}

	//virtual void SetMoney(int money)   //입금
	//{
	//	Account::SetMoney(money + money*interestRatio*0.01);
	//	//입금 + (입금 * 이자율)
	//}
};


Account::Account(int accId, int balance, char *name)
	: accId(accId), balance(balance)
{
	this->name = new char[strlen(name) + 1]; 
	strcpy(this->name, name);
}

Account::Account(const Account& ref)             
	:accId(ref.accId), balance(ref.balance)
{
	this->name = new char[strlen(ref.name) + 1];
	strcpy(this->name, ref.name);
}

Account::~Account()  
{
	delete[] name;  
}

int Account::GetAccId() const  //계좌ID 반환
{
	return accId;
}

int Account::GetMoney(int money)  //출금
{
	this->balance -= money;
	return balance;
}

void Account::SetMoney(int money) //입금
{
	this->balance += money;
}

void Account::ShowAccount() const  //계좌정보 출력
{
	cout << "계좌ID: " << accId << endl;
	cout << "이름: " << name << endl;
	cout << "입금액: " << balance << endl;
}



/*계좌정보 처리 클래스*/
class AccountHandler
{
private:
	Account *accArr[ACCOUNT_LEN];  //고객 계좌정보 저장 포인터 객체 배열
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
void AccountHandler::MakeAccount()
{
	cout << endl << "[계좌종류선택]" << endl;
	cout <<"1.보통예금계좌 2.신용신뢰계좌" << endl;
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

	accArr[accNum++] = new HighCreditAccount(accID, money, name, ratio, special);
	cout << "신용신뢰계좌가 개설되었습니다." << endl;
}

//입금
void AccountHandler::Deposit()
{
	cout << endl<<"[입 금]" << endl;
	
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
		cout << endl<<"[NUM : " << i + 1 <<" ]"<< endl;
		accArr[i]->ShowAccount();
	}
}



int main()
{
	AccountHandler ac;
	while (1)
	{
		ShowMenu();   //메뉴출력
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

