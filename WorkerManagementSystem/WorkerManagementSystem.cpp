#include "WorkerManager.h"
#include "Boss.h"
#include "Manager.h"
#include "Employee.h"



int main()
{
	WorkerManager worker_manager;
	int choice = -1;

	while (true)
	{
		worker_manager.ShowMenu();

		cout << "\nPlease select a function" << endl;
		cin >> choice;

		switch (choice)
		{
			//�˳�ϵͳ
		case 0:
			worker_manager.ExitSystem();

			//���Ա��
		case 1:
			worker_manager.AddWorker();
			break;

			//չʾ����Ա����Ϣ
		case 2:
			worker_manager.ShowWorkers();
			break;

			//ɾ��Ա����Ϣ
		case 3:
			worker_manager.DeleteWorker();
			break;

			//�޸�Ա����Ϣ
		case 4:
			worker_manager.ModifyWorker();
			break;

			//����Ա��
		case 5:
			worker_manager.FindWorker();
			break;

			//��ְ���������
		case 6:
			worker_manager.SortWorkers();
			break;

			//��չ����ĵ�
		case 7:
			worker_manager.ClearWorkers();
			break;

		default:
			cout << "Please enter the correct option" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	system("pause");
	return EXIT_SUCCESS;
}
