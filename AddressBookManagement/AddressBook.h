#pragma once
#include <iostream>
#include <string>

//����¼1000��
#define MAX_PEOPLE_TO_CONTACT 1000

using namespace std;

//��ϵ����Ϣ
struct PERSON
{
	//����
	string m_name;
	//�Ա�
	int m_gender;
	//����
	int m_age;
	//��ϵ�绰
	string m_phone;
	//��ͥסַ
	string m_address;
};

struct ADDRESS_BOOK
{
	struct PERSON m_AddressBook[MAX_PEOPLE_TO_CONTACT];

	int m_Size = 0;
};


//��ʾͨѶ¼����ϵͳ�˵�
void ShowMenu();

//�����ϵ��
void AddContact(struct ADDRESS_BOOK* addrbook);

//��ʾ��ϵ��
void ShowContacts(struct ADDRESS_BOOK* addrbook);

//�鿴��ϵ���Ƿ����
int IsExist(struct ADDRESS_BOOK* addrbook, string name);

//ɾ����ϵ��
void DeleteContact(struct ADDRESS_BOOK* addrbook);

//������ϵ��
void FindContact(struct ADDRESS_BOOK* addrbook);

//�޸���ϵ��
void ModifyContact(struct ADDRESS_BOOK* addrbook);

//�����ϵ��
void ClearContacts(struct ADDRESS_BOOK* addrbook);

