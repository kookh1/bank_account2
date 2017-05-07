#include<iostream>
#include<cstring>
using namespace std;


/* constant ���� */
enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT};  //�޴� ����
enum{NORMAL=1, CREDIT};   //�������� ����

const int NAME_LEN = 20;     //�̸� ����
const int ACCOUNT_LEN = 100; //���� ����


/*�� �������� Ŭ����*/
class Account  
{
private:     
	int accId;   //���¹�ȣ
	int balance; //�ܾ�
	char *name;  //�̸�

public:
	Account(int accId, int balance, char *name);  
	Account(const Account& ref);  
	~Account();  

	int GetAccId() const;     //����ID ��ȯ
	int GetMoney(int money);  //���
	virtual void SetMoney(int money) = 0; //�Ա�
	virtual void ShowAccount() const=0;   //�������� ���
};

/*����������� Ŭ����*/
class NormalAccount : public Account
{
private:
	int interestRatio;  //������
public:
	NormalAccount(int accId, int balance, char *name, int ratio) 
		: Account(accId, balance, name), interestRatio(ratio)
	{}
	
	virtual void ShowAccount() const  //�������� ���
	{
		Account::ShowAccount();
		cout << "������: " << interestRatio << endl;	
	}

	virtual void SetMoney(int money)   //�Ա�
	{
		Account::SetMoney(money+ money*interestRatio*0.01);
		//�Ա� + (�Ա� * ������)
	}
};

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

	//virtual void SetMoney(int money)   //�Ա�
	//{
	//	Account::SetMoney(money + money*interestRatio*0.01);
	//	//�Ա� + (�Ա� * ������)
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

int Account::GetAccId() const  //����ID ��ȯ
{
	return accId;
}

int Account::GetMoney(int money)  //���
{
	this->balance -= money;
	return balance;
}

void Account::SetMoney(int money) //�Ա�
{
	this->balance += money;
}

void Account::ShowAccount() const  //�������� ���
{
	cout << "����ID: " << accId << endl;
	cout << "�̸�: " << name << endl;
	cout << "�Աݾ�: " << balance << endl;
}



/*�������� ó�� Ŭ����*/
class AccountHandler
{
private:
	Account *accArr[ACCOUNT_LEN];  //�� �������� ���� ������ ��ü �迭
	int accNum = 0;                //���� ����

public:
	/*���� ���� ���� ���*/
	AccountHandler();      //empty
	~AccountHandler();     //�������� ����
	void ShowMenu();       //�޴� ���
	void MakeAccount();    //���� �����
	void Deposit();        //�Ա�
	void Withdraw();       //���
	void ShowAllAccount(); //��� ���� ���

	void MakeNormalAccount();  //������� �����
	void MakeCreditAccount();  //�ſ�ŷڰ��� �����
};

//empty
AccountHandler::AccountHandler()
{}

//�������� ����
AccountHandler::~AccountHandler()
{
	for (int i = 0; i < accNum; i++)
		delete accArr[i];
}

           
//�޴� ���
void ShowMenu()
{
	cout << "------Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
	cout << "����: ";
}


//���� �����
void AccountHandler::MakeAccount()
{
	cout << endl << "[������������]" << endl;
	cout <<"1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
	int sel;
	cout << "����: ";
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

//������� �����
void AccountHandler::MakeNormalAccount()
{
	int accID;
	cout << "����ID: ";
	cin >> accID;

	char name[NAME_LEN];
	cout << "�̸�: ";
	cin >> name;

	int money;
	cout << "�Աݾ�: ";
	cin >> money;

	int ratio;
	cout << "������: ";
	cin >> ratio;

	accArr[accNum++] = new NormalAccount(accID, money, name, ratio); 
	cout << "������°� �����Ǿ����ϴ�." << endl;
}

//�ſ�ŷڰ��� �����
void AccountHandler::MakeCreditAccount()
{
	int accID;
	cout << "����ID: ";
	cin >> accID;

	char name[NAME_LEN];
	cout << "�̸�: ";
	cin >> name;

	int money;
	cout << "�Աݾ�: ";
	cin >> money;

	int ratio;
	cout << "������: ";
	cin >> ratio;

	int special;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
	cin >> special;

	accArr[accNum++] = new HighCreditAccount(accID, money, name, ratio, special);
	cout << "�ſ�ŷڰ��°� �����Ǿ����ϴ�." << endl;
}

//�Ա�
void AccountHandler::Deposit()
{
	cout << endl<<"[�� ��]" << endl;
	
	int accID;   //����ID
	cout << "����ID: ";
	cin >> accID;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accID)
		{
			int money;  //�Աݾ�
			cout << "�Աݾ�: ";
			cin >> money;
			accArr[i]->SetMoney(money);
			cout << "�ԱݿϷ�" << endl;
			return;
		}
	}
	cout << "�ش� ����ID�� �������� �ʽ��ϴ�." << endl;
}


//���
void AccountHandler::Withdraw()
{
	cout << endl << "[�� ��]" << endl;

	int accID;   //����ID
	cout << "����ID: ";
	cin >> accID;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i]->GetAccId() == accID)
		{
			int money;  //��ݾ�
			cout << "��ݾ�: ";
			cin >> money;
			accArr[i]->GetMoney(money);
			cout << "��ݿϷ�" << endl;
			return;
		}
	}
	cout << "�ش� ����ID�� �������� �ʽ��ϴ�." << endl;
}


//��� ���� ���
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
		ShowMenu();   //�޴����
		int sel;
		cin >> sel;

		switch (sel)
		{
		case MAKE:
			ac.MakeAccount();  //���¸����
			break;
		case DEPOSIT:
			ac.Deposit();     //�Ա��ϱ�
			break;
		case WITHDRAW:
			ac.Withdraw();    //����ϱ�
			break;
		case SHOW:
			ac.ShowAllAccount();  //���������
			break;
		case EXIT:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		cout << endl;
	}

	return 0;
}

