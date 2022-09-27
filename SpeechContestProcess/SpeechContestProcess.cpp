#include "SpeechContestManager.h"

int main()
{
	srand((unsigned int)time(NULL));
	SpeechContestManager manager;
	/*
		for (map<int, Speaker>::iterator it = manager.m_Speaker.begin(); it != manager.m_Speaker.end(); it++)
		{
			cout << "Speaker's number: " << it->first << " name: " << it->second.m_Name << endl;
		}
	*/

	int choice;

	while (true)
	{
		manager.ShowMenu();

		cout << "\nPlease enter your choice" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0:
			manager.ExitContest();
		case 1:
			manager.StartSpeech();
			break;
		case 2:
			manager.ShowRecord();
			break;
		case 3:
			manager.ClearRecord();
			break;
		default:
			cout << "\nPlease Enter correct choice";
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}