#include "AccountHandler.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

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
void AccountHandler::ShowMenu()
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
	cout << "1.���뿹�ݰ��� 2.�ſ�ŷڰ���" << endl;
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
	cout << "�ſ�ŷڰ��°� �����Ǿ����ϴ�." << endl;
}

//�Ա�
void AccountHandler::Deposit()
{
	cout << endl << "[�� ��]" << endl;

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
		cout << endl << "[NUM : " << i + 1 << " ]" << endl;
		accArr[i]->ShowAccount();
	}
}
