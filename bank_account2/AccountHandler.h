#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"


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

#endif