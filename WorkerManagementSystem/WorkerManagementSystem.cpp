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
			//退出系统
		case 0:
			worker_manager.ExitSystem();

			//添加员工
		case 1:
			worker_manager.AddWorker();
			break;

			//展示所有员工信息
		case 2:
			worker_manager.ShowWorkers();
			break;

			//删除员工信息
		case 3:
			worker_manager.DeleteWorker();
			break;

			//修改员工信息
		case 4:
			worker_manager.ModifyWorker();
			break;

			//查找员工
		case 5:
			worker_manager.FindWorker();
			break;

			//按职工编号排序
		case 6:
			worker_manager.SortWorkers();
			break;

			//清空管理文档
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
