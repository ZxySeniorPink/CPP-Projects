#include "AddressBook.h"


void ShowMenu()
{
	cout << " ------------------------------------------ " << endl;
	cout << "|=== WELCOME TO ADDRESS BOOK MANAGEMENT ===|" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << "|**********   1: ADD PERSON      **********|" << endl;
	cout << "|**********   2: SHOW PERSONS    **********|" << endl;
	cout << "|**********   3: DELETE PERSON   **********|" << endl;
	cout << "|**********   4: FIND PERSON     **********|" << endl;
	cout << "|**********   5: MODIFY PERSON   **********|" << endl;
	cout << "|**********   6: CLEAR PERSONS   **********|" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << "|                       ...PRESS 0 TO EXIT |" << endl;
	cout << " ------------------------------------------ " << endl;
}


//添加联系人
void AddContact(struct ADDRESS_BOOK* addrbook)
{
	if (addrbook == NULL)
	{
		cout << "Address book does not exist" << endl;
		return;
	}
	cout << "\nPlease enter name" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_name;

	int gender = -1;
	cout << "\nPlease enter gender" << endl;
	cout << "0 --> female\n1 --> male" << endl;

	while (true)
	{
		cin >> gender;
		if (gender == 0 || gender == 1)
		{
			addrbook->m_AddressBook[addrbook->m_Size].m_gender = gender;
			break;
		}
		cout << "enter error, please enter again\n" << endl;
	}

	cout << "\nPlease enter age" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_age;

	cout << "\nPlease enter telephone number" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_phone;

	cout << "\nPlease enter address" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_address;

	addrbook->m_Size++;

	cout << "\n\n\t\t\t[ Add successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}

//显示联系人
void ShowContacts(struct ADDRESS_BOOK* addrbook)
{
	if (addrbook == NULL)
	{
		cout << "Address book does not exist" << endl;
		return;
	}
	if (addrbook->m_Size == 0)
	{
		cout << "The address book is empty" << endl;
		return;
	}
	for (int i = 0; i < addrbook->m_Size; i++)
	{
		cout << "Name: " << addrbook->m_AddressBook[i].m_name << "\t";
		cout << "Gender: " << (addrbook->m_AddressBook[i].m_gender == 0 ? "female" : "male") << "\t";
		cout << "Age: " << addrbook->m_AddressBook[i].m_age << "\t\t";
		cout << "Phone: " << addrbook->m_AddressBook[i].m_phone << "\t";
		cout << "Address: " << addrbook->m_AddressBook[i].m_address << "\t";
		cout << endl;
	}

	cout << "\n\n\t\t\t[ Show successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}

//查看联系人是否存在
int IsExist(struct ADDRESS_BOOK* addrbook, string name)
{
	if (addrbook == NULL)
	{
		cout << "Address book does not exist" << endl;
		return -1;
	}
	for (int i = 0; i < addrbook->m_Size; i++)
	{
		if (addrbook->m_AddressBook[i].m_name == name)
			return i;
	}
	return -1;
}

//删除联系人
void DeleteContact(struct ADDRESS_BOOK* addrbook)
{
	if (addrbook == NULL)
	{
		cout << "\nAddress book does not exist" << endl;
		return;
	}
	if (addrbook->m_Size == 0)
	{
		cout << "\nThe address book is empty" << endl;
		system("pause");
		system("cls");
		ShowMenu();
		return;
	}

	cout << "\nPlease enter the person's name who which wanna delete" << endl;
	string name;
	cin >> name;
	int res = IsExist(addrbook, name);
	if (res == -1)
	{
		cout << "No person exist" << endl;
	}
	else
	{
		for (int i = res; res < addrbook->m_Size - 1; i++)
		{
			addrbook->m_AddressBook[i] = addrbook->m_AddressBook[i + 1];
		}
	}
	addrbook->m_Size--;
	cout << "\n\n\t\t\t[ Delete successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}

//查找联系人
void FindContact(struct ADDRESS_BOOK* addrbook)
{
	if (addrbook == NULL)
	{
		cout << "\nAddress book does not exist" << endl;
		return;
	}
	if (addrbook->m_Size == 0)
	{
		cout << "\nThe address book is empty" << endl;
		system("pause");
		system("cls");
		ShowMenu();
		return;
	}

	string name;
	cout << "\nPlease enter person's name which you wanna find" << endl;
	cin >> name;

	int res = IsExist(addrbook, name);
	if (res == -1)
	{
		cout << "\nNo person exist" << endl;
	}
	else
	{
		cout << "Name: " << addrbook->m_AddressBook[res].m_name << "\t";
		cout << "Gender: " << (addrbook->m_AddressBook[res].m_gender == 0 ? "female" : "male") << "\t";
		cout << "Age: " << addrbook->m_AddressBook[res].m_age << "\t\t";
		cout << "Phone: " << addrbook->m_AddressBook[res].m_phone << "\t";
		cout << "Address: " << addrbook->m_AddressBook[res].m_address << "\t";
		cout << endl;
	}

	cout << "\n\n\t\t\t[ Find successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}

//修改联系人
void ModifyContact(struct ADDRESS_BOOK* addrbook)
{
	if (addrbook == NULL)
	{
		cout << "\nAddress book does not exist" << endl;
		return;
	}
	if (addrbook->m_Size == 0)
	{
		cout << "\nThe address book is empty" << endl;
		system("pause");
		system("cls");
		ShowMenu();
		return;
	}

	string name;
	cout << "\nPlease enter person's name which you wanna modify" << endl;
	cin >> name;

	int res = IsExist(addrbook, name);
	if (res == -1)
	{
		cout << "\nNo person exist" << endl;
	}
	else
	{
		cout << "\nPlease enter name" << endl;
		cin >> addrbook->m_AddressBook[res].m_name;

		int gender = -1;
		cout << "\nPlease enter gender" << endl;
		cout << "0 --> female\n1 --> male" << endl;

		while (true)
		{
			cin >> gender;
			if (gender == 0 || gender == 1)
			{
				addrbook->m_AddressBook[res].m_gender = gender;
				break;
			}
			cout << "\nenter error, please enter again\n" << endl;
		}

		cout << "\nPlease enter age" << endl;
		cin >> addrbook->m_AddressBook[res].m_age;

		cout << "\nPlease enter telephone number" << endl;
		cin >> addrbook->m_AddressBook[res].m_phone;

		cout << "\nPlease enter address" << endl;
		cin >> addrbook->m_AddressBook[res].m_address;
	}

	cout << "\n\n\t\t\t[ Modify successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}

//清空联系人
void ClearContacts(struct ADDRESS_BOOK* addrbook)
{
	if (addrbook == NULL)
	{
		cout << "\nAddress book does not exist" << endl;
		return;
	}
	if (addrbook->m_Size == 0)
	{
		cout << "\nThe address book is empty" << endl;
		system("pause");
		system("cls");
		ShowMenu();
		return;
	}

	addrbook->m_Size = 0;

	cout << "\n\n\t\t\t[ Clear successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}
