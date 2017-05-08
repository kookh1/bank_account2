#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "BankingCommonDecl.h"
#include "String.h"

/*�� �������� Ŭ����*/
class Account
{
private:
	int accId;   //���¹�ȣ
	int balance; //�ܾ�
	String name; //�̸�

public:
	Account(int accId, int balance, String name);
	
	int GetAccId() const;     //����ID ��ȯ
	int GetMoney(int money);  //���
	virtual void SetMoney(int money) = 0; //�Ա�
	virtual void ShowAccount() const = 0;   //�������� ���
};

#endif
