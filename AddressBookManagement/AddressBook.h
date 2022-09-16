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

//ɾ����ϵ��
void DeleteContact();

//������ϵ��
void FindContact();

//�޸���ϵ��
void ModifyContact();

//�����ϵ��
void ClearContacts();

