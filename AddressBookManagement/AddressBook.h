#pragma once
#include <iostream>
#include <string>

//最多记录1000人
#define MAX_PEOPLE_TO_CONTACT 1000

using namespace std;

//联系人信息
struct PERSON
{
	//姓名
	string m_name;
	//性别
	int m_gender;
	//年龄
	int m_age;
	//联系电话
	string m_phone;
	//家庭住址
	string m_address;
};

struct ADDRESS_BOOK
{
	struct PERSON m_AddressBook[MAX_PEOPLE_TO_CONTACT];

	int m_Size = 0;
};

//显示通讯录管理系统菜单
void ShowMenu();

//添加联系人
void AddContact(struct ADDRESS_BOOK* addrbook);

//显示联系人
void ShowContacts(struct ADDRESS_BOOK* addrbook);

//删除联系人
void DeleteContact();

//查找联系人
void FindContact();

//修改联系人
void ModifyContact();

//清空联系人
void ClearContacts();

