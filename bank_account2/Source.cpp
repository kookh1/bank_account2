#include<iostream>
using namespace std;

/*�� ���� ���� ������*/
struct Account  
{
	int accId;   //���¹�ȣ
	int balance; //�ܾ�
	char *name;  //�̸�
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
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			cout << "���α׷��� �����մϴ�." << endl;
			return 0;
		default:
			cout << "�߸��� �Է��Դϴ�." << endl;
		}
		cout << endl;
	}

	return 0;
}