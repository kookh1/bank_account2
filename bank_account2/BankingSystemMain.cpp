#include "Account.h"
#include "AccountHandler.h"


int main()
{
	AccountHandler ac;
	while (1)
	{
		ac.ShowMenu();   //�޴����
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

