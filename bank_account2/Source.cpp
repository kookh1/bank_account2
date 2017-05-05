#include<iostream>
using namespace std;


/* constant ���� */
enum{MAKE=1, DEPOSIT, WITHDRAW, SHOW, EXIT};

/*�� ���� ���� ������*/
struct Account  
{
	int accId;   //���¹�ȣ
	int balance; //�ܾ�
	char name[20];  //�̸�
};

struct Account accArr[100];  //�� ���� ���� �迭
int accNum = 0;              //���� ����


/*�� ���� ���� �Լ�*/
int GetAccId();             //����ID ��������
int GetBalance();           //�ܾ� �ҷ�����
void SetBalance(int money); //�Ա��ϱ�


/*���� ���� ���� ���*/
void ShowMenu();       //�޴� ���
void MakeAccount();    //���� �����
void Deposit();        //�Ա�
void Withdraw();       //���
void ShowAllAccount(); //��� ���� ���


int main()
{
	while (1)
	{
		cout << "------Menu-----" << endl;
		cout << "1. ���°���" << endl;
		cout << "2. �Ա�" << endl;
		cout << "3. ���" << endl;
		cout << "4. �������� ��ü ���" << endl;
		cout << "5. ���α׷� ����" << endl;
		int sel;
		cout << "����: ";
		cin >> sel;

		switch (sel)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			break;
		case WITHDRAW:
			break;
		case SHOW:
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


//���� �����
void MakeAccount()
{
	cout << endl<<"[���°���]" << endl;

	Account myAcc;
	int accID;
	cout << "����ID: ";
	cin >> myAcc.accId;

	cout << "�̸�: ";
	cin >> myAcc.name;

	cout << "�Աݾ�: ";
	cin >> myAcc.balance;

	accArr[accNum++] = myAcc;  //���� 1���� ���� ���� ����ҿ� ����
	cout << "���°� �����Ǿ����ϴ�." << endl;
}