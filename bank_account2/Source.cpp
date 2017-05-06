#include<iostream>
#include<cstring>
using namespace std;


/* constant ���� */
enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT};

/*�� ���� ���� ������*/
class Account  
{
private:     
	int accId;   //���¹�ȣ
	int balance; //�ܾ�
	char *name;  //�̸�

public:
	Account(int accId, int balance, char *name)  //������
		: accId(accId), balance(balance)
	{
		this->name = new char[strlen(name) + 1];  //�̸� �����Ҵ�
		strcpy(this->name, name);
	}
	Account(const Account& ref)                 //���� ���� ������ 
		:accId(ref.accId), balance(ref.balance)
	{
		this->name = new char[strlen(ref.name) + 1];
		strcpy(this->name, ref.name);
	}
	~Account()  //�Ҹ���
	{
		delete[] name;  //�̸� �����Ҵ� ����
	}
	int GetAccId() const  //����ID ��ȯ
	{
		return accId;
	}
	int GetMoney(int money)  //���
	{
		this->balance -= money;
		return balance;
	}
	void SetMoney(int money) //�Ա�
	{
		this->balance += money;
	}
	void ShowAccount() const  //�������� ���
	{
		cout << "����ID: " << accId << endl;
		cout << "�̸�: " << name << endl;
		cout << "�Աݾ�: " << balance << endl << endl;
	}
};

Account *accArr[100];  //�� ���� ���� �迭
int accNum = 0;              //���� ����



/*���� ���� ���� ���*/
void ShowMenu();       //�޴� ���
void MakeAccount();    //���� �����
void Deposit();        //�Ա�
void Withdraw();       //���
void ShowAllAccount(); //��� ���� ���


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
void MakeAccount()
{
	cout << endl << "[���°���]" << endl;

	int accID;
	cout << "����ID: ";
	cin >> accID;

	char name[20];
	cout << "�̸�: ";
	cin >> name;

	int money;
	cout << "�Աݾ�: ";
	cin >> money;

	Account *myAcc = new Account(accID, money, name);  //���� ��ü ����
	accArr[accNum++] = myAcc;  //���� 1���� ���� ���� ����ҿ� ����
	cout << "���°� �����Ǿ����ϴ�." << endl;
}


//�Ա�
void Deposit()
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
void Withdraw()
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
void ShowAllAccount()
{
	for (int i = 0; i < accNum; i++)
	{
		cout << endl<<"[NUM : " << i + 1 <<" ]"<< endl;
		accArr[i]->ShowAccount();
	}
}



int main()
{

	while (1)
	{
		ShowMenu();   //�޴����
		int sel;
		cin >> sel;

		switch (sel)
		{
		case MAKE:
			MakeAccount();  //���¸����
			break;
		case DEPOSIT:
			Deposit();     //�Ա��ϱ�
			break;
		case WITHDRAW:
			Withdraw();    //����ϱ�
			break;
		case SHOW:
			ShowAllAccount();  //���������
			break;
		case EXIT:
			for (int i = 0; i < accNum; i++)  //��ü �޸� ����
				delete accArr[i];
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		cout << endl;
	}

	return 0;
}

