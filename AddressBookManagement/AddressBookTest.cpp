#include "AddressBook.h"

int main()
{
	struct ADDRESS_BOOK addrbook;
	ShowMenu();

	int select = 0;

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

			break;
		case 4:

			break;
		case 5:

			break;
		case 6:

			break;
		case 0:
			system("cls");
			cout << "Welcome to use again!" << endl;
			return 0;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
