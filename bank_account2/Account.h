#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "BankingCommonDecl.h"

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
	Account& operator=(const Account& ref);  
	~Account();
	
	int GetAccId() const;     //����ID ��ȯ
	int GetMoney(int money);  //���
	virtual void SetMoney(int money) = 0; //�Ա�
	virtual void ShowAccount() const = 0;   //�������� ���
};

#endif
