#include "AddressBook.h"

void ShowMenu()
{
	cout << " ------------------------------------------ " << endl;
	cout << "|=== WELCOME TO ADDRESS BOOK MANAGEMENT ===|" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << "|**********   1: ADD CONTACT     **********|" << endl;
	cout << "|**********   2: SHOW CONTACTS   **********|" << endl;
	cout << "|**********   3: DELETE CONTACT  **********|" << endl;
	cout << "|**********   4: FIND CONTACT    **********|" << endl;
	cout << "|**********   5: MODIFY CONTACT  **********|" << endl;
	cout << "|**********   6: CLEAR CONTACTS  **********|" << endl;
	cout << "|------------------------------------------|" << endl;
	cout << "|                       ...PRESS 0 TO EXIT |" << endl;
	cout << " ------------------------------------------ " << endl;
}

//添加联系人
void AddContact(struct ADDRESS_BOOK* addrbook)
{
	cout << "\nPlease enter name" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_name;

	int gender = -1;
	cout << "\nPlease enter gender" << endl;
	cout << "0 --> female\n1 --> male" << endl;
	cin >> gender;
	while (gender == 0 || gender == 1)
	{
		addrbook->m_AddressBook[addrbook->m_Size].m_gender = gender;
		break;
	}

	cout << "\nPlease enter age" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_age;

	cout << "\nPlease enter telephone number" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_phone;

	cout << "\nPlease enter address" << endl;
	cin >> addrbook->m_AddressBook[addrbook->m_Size].m_address;

	addrbook->m_Size++;
	
	cout << "\n\t\t\t[ Add successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}

//显示联系人
void ShowContacts(struct ADDRESS_BOOK* addrbook)
{
	for (int i = 0; i < addrbook->m_Size; i++)
	{
		cout << "Name: " << addrbook->m_AddressBook[i].m_name << "\t";
		cout << "Gender: " << (addrbook->m_AddressBook[i].m_gender == 0 ? "female" : "male") << "\t";
		cout << "Age: " << addrbook->m_AddressBook[i].m_age << "\t";
		cout << "Phone: " << addrbook->m_AddressBook[i].m_phone << "\t";
		cout << "Address: " << addrbook->m_AddressBook[i].m_address << "\t";
		cout << endl;
	}

	cout << "\n\t\t\t[ Show successfully! ]" << endl;
	system("pause");
	system("cls");
	ShowMenu();
}

