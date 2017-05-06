#include<iostream>
using namespace std;


/* constant ���� */
enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT};

/*�� ���� ���� ������*/
class Account  
{
public:  //temporary!!!
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
	~Account()  //�Ҹ���
	{
		delete[] name;  //�̸� �����Ҵ� ����
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
		if (accArr[i]->accId == accID)
		{
			int money;  //�Աݾ�
			cout << "�Աݾ�: ";
			cin >> money;
			accArr[i]->balance += money;
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
		if (accArr[i]->accId == accID)
		{
			int money;  //��ݾ�
			cout << "��ݾ�: ";
			cin >> money;
			accArr[i]->balance -= money;
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
		cout << "����ID: " << accArr[i]->accId << endl;
		cout << "�̸�: " << accArr[i]->name << endl;
		cout << "�Աݾ�: " << accArr[i]->balance << endl<<endl;
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
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		cout << endl;
	}

	return 0;
}

