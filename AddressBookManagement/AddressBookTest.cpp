#include "AddressBook.h"

int main()
{
	ShowMenu();
	int select = 0;
	struct ADDRESS_BOOK addrbook;

	while (true)
	{
		cout << "Please select an operation" << endl;
		cin >> select;
		switch (select)
		{
		case 1:
			AddContact(&addrbook);
			break;
		case 2:
			ShowContacts(&addrbook);
			break;
		case 3:
			DeleteContact(&addrbook);
			break;
		case 4:
			FindContact(&addrbook);
			break;
		case 5:
			ModifyContact(&addrbook);
			break;
		case 6:
			ClearContacts(&addrbook);
			break;
		case 0:
			system("cls");
			cout << "Look forward to your next use!" << endl;
			return 0;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
