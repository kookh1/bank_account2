#ifndef __BANKING_COMMON_DECL_H__
#define __BANKING_COMMON_DECL_H__

#include<iostream>
#include<cstring>
using namespace std;


/* constant 정보 */
enum{ MAKE = 1, DEPOSIT, WITHDRAW, SHOW, EXIT };  //메뉴 선택
enum{ NORMAL = 1, CREDIT };   //계좌종류 선택
enum{ LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };  //신용등급 선택

const int NAME_LEN = 20;     //이름 길이
const int ACCOUNT_LEN = 100; //계좌 개수

#endif
