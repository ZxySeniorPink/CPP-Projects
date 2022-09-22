#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	if (!ifs.is_open())
	{
		//��ʼ����Ա
		this->m_FileIsEmpty = true;
		this->m_workers_num = 0;
		this->m_workers = NULL;

		ifs.close();
		return;
	}

	//2���ļ����� ����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		this->m_FileIsEmpty = true;
		this->m_workers_num = 0;
		this->m_workers = NULL;

		ifs.close();
		return;
	}

	//3���ļ����ڣ����Ҽ�¼����
	int num = this->GetWorkersNum();
	this->m_workers_num = num;
	this->m_workers = new Worker * [this->m_workers_num];
	this->InitWorker();
}

void WorkerManager::ShowMenu()
{
	cout << "|-------------------------------------------|" << endl;
	cout << "|=== WELCOME TO WORKER MANAGEMENT SYSTEM ===|" << endl;
	cout << "|-------------------------------------------|" << endl;
	cout << "|**********    1: ADD WORKER      **********|" << endl;
	cout << "|**********    2: SHOW WORKERS    **********|" << endl;
	cout << "|**********    3: DELETE WORKER   **********|" << endl;
	cout << "|**********    4: MODIFY WORKER   **********|" << endl;
	cout << "|**********    5: FIND WORKER     **********|" << endl;
	cout << "|**********    6: SORT WORKERS    **********|" << endl;
	cout << "|**********    7: CLEAR WORKERS   **********|" << endl;
	cout << "|-------------------------------------------|" << endl;
	cout << "|                        ...PRESS 0 TO EXIT |" << endl;
	cout << "|-------------------------------------------|" << endl;
}

void WorkerManager::ExitSystem()
{
	system("cls");
	cout << "Look forward to your next use!" << endl;
	exit(0);
}

void WorkerManager::InitWorker()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dept_id;
	
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dept_id)
	{
		Worker* worker = NULL;
		if (dept_id == 1)
		{
			worker = new Employee(id, name, dept_id);
		}
		else if (dept_id == 2)
		{
			worker = new Manager(id, name, dept_id);
		}
		else if (dept_id == 3)
		{
			worker = new Boss(id, name, dept_id);
		}
		else
		{
			cout << "\nNo exist this post" << endl;
			continue;
		}
		this->m_workers[index] = worker;
		index++;
	}
	ifs.close();
}

void WorkerManager::AddWorker()
{
	cout << "\nPlease enter the number of added workers" << endl;
	int add_num = 0;
	cin >> add_num;

	if (add_num > 0)
	{
		//���
		//��������¿ռ��С
		int new_size = this->m_workers_num + add_num;
		Worker** new_space = new Worker * [new_size];
		
		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->m_workers != NULL)
		{
			for (int i = 0; i < this->m_workers_num; i++)
			{
				new_space[i] = this->m_workers[i];
			}
		}

		//�������������
		for (int i = 0; i < add_num; i++)
		{
			int id;
			string name;
			int dept_id;
			int dept_choice;

			cout << "\nPlease enter No." << i + 1 << "'s id" << endl;
			cin >> id;

			cout << "\nPlease enter No." << i + 1 << "'s name" << endl;
			cin >> name;

			cout << "\nPlease choose worker's post" << endl;
			cout << "1��Employee" << endl;
			cout << "2��Manager" << endl;
			cout << "3��Boss" << endl;
			cin >> dept_choice;

			Worker* worker = NULL;
			switch (dept_choice)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				cout << "\nPlease enter the correct post number!" << endl;
				break;
			}

			new_space[this->m_workers_num + i] = worker;
		}
		
		//�ͷ�ԭ�еĿռ�
		delete[] this->m_workers;

		//�����¿ռ��ָ��
		this->m_workers = new_space;

		//�����µ�ְ������
		this->m_workers_num += add_num;

		//����ְ����Ϊ�ձ�־
		this->m_FileIsEmpty = false;

		//��ʾ��ӳɹ�
		cout << "\nAdd successfully!" << endl;

		//�������ݵ��ļ���
		this->Save();
	}

	else
	{
		cout << "\nThe data entered is incorrect" << endl;
	}

	system("pause");
	system("cls");
}


void WorkerManager::Save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	//��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_workers_num; i++)
	{
		ofs << this->m_workers[i]->m_Id << " "
			<< this->m_workers[i]->m_Name << " "
			<< this->m_workers[i]->m_DeptId << endl;
	}

	ofs.close();
}

int WorkerManager::GetWorkersNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int dept_id;

	int num = 0;

	while (ifs >> id && ifs >> name && ifs >> dept_id)
	{
		num++;
	}

	return num;
}

void WorkerManager::ShowWorkers()
{
	if (this->m_FileIsEmpty)
	{
		cout << "\nNo workers' flie or workers' file is null." << endl;
		
	}
	else
	{
		for (int i = 0; i < this->m_workers_num; i++)
		{
			//���ö�̬���ó���ӿ�
			this->m_workers[i]->ShowInfo();
		}
	}

	system("pause");
	system("cls");
}

//�ж�ְ���Ƿ����  ������ڷ���ְ�����������е�λ�ã������ڷ���-1
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_workers_num; i++)
	{
		if (this->m_workers[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void WorkerManager::DeleteWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "\nNo workers' flie or workers' file is null." << endl;
	}
	else
	{
		cout << "\nPlease enter the worker's id who you want to delete." << endl;
		int id;
		cin >> id;

		int res = this->IsExist(id);

		if (res != -1)
		{
			for (int i = res; i < this->m_workers_num; i++)
			{
				this->m_workers[i] = this->m_workers[i + 1];
			}
			this->m_workers_num--;
			this->Save();
			cout << "\nDelete successfully!" << endl;
		}
		else
		{
			cout << "\nDelete failed, not found this worker." << endl;
		}
	}

	system("pause");
	system("cls");
}

void WorkerManager::ModifyWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "\nNo workers' flie or workers' file is null." << endl;
	}
	else
	{
		cout << "\nPlease enter the worker's id who you want to modify." << endl;
		int id;
		cin >> id;
		int res = this->IsExist(id);

		if (res != -1)
		{
			delete this->m_workers[res];

			int new_id = 0;
			string new_name = "";
			int new_dept_choice = 0;
			
			cout << "\nHave found worker" << id << " Please enter new department id" << endl;
			cin >> new_id;

			cout << "\nPlease enter new name" << endl;
			cin >> new_name;

			cout << "\nPlease choose worker's post" << endl;
			cout << "1��Employee" << endl;
			cout << "2��Manager" << endl;
			cout << "3��Boss" << endl;
			cin >> new_dept_choice;

			Worker* worker = NULL;
			switch (new_dept_choice)
			{
			case 1:
				worker = new Employee(new_id, new_name, new_dept_choice);
				break;
			case 2:
				worker = new Manager(new_id, new_name, new_dept_choice);
				break;
			case 3:
				worker = new Boss(new_id, new_name, new_dept_choice);
				break;
			default:
				cout << "\nPlease enter the correct post number!" << endl;
				break;
			}

			//�������ݵ�������
			this->m_workers[res] = worker;

			cout << "\nModify successfully!" << endl;

			//���浽�ļ���
			this->Save();
		}
		else
		{
			cout << "\nModify failed, not found." << endl;
		}
	}

	system("pause");
	system("cls");
}


void WorkerManager::FindWorker()
{
	if (this->m_FileIsEmpty)
	{
		cout << "\nNo workers' flie or workers' file is null." << endl;
	}
	else
	{
		cout << "\nPlease enter the way to find" << endl;
		cout << "1��find by worker's id" << endl;
		cout << "2��find by worker's name" << endl;
		
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			int id;
			cout << "\nPlease enter the worker's id who you want to find" << endl;
			cin >> id;
			
			int res = this->IsExist(id);
			if (res != -1)
			{
				cout << "\nFind successfully!" << endl;
				this->m_workers[res]->ShowInfo();
			}
			else
			{
				cout << "\nFind failed, not found." << endl;
			}
		}
		else if (choice == 2)
		{
			string name;
			cout << "\nPlease enter the worker's name who you want to find" << endl;
			cin >> name;
			
			//�����ж��Ƿ�鵽�ı�־
			//Ĭ��Ϊδ�ҵ���ְ��
			bool flag = false;

			for (int i = 0; i < this->m_workers_num; i++)
			{
				if (this->m_workers[i]->m_Name == name)
				{
					cout << "\nFind successfully!" << endl;
					this->m_workers[i]->ShowInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "\nFind failed, not found." << endl;
			}
		}
		else
		{
			cout << "\nInvaild choice" << endl;
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::SortWorkers()
{
	if (this->m_FileIsEmpty)
	{
		cout << "\nNo workers' flie or workers' file is null." << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "\nPlease choose the way to sort" << endl;
		cout << "1��Ascending" << endl;
		cout << "2��Descending" << endl;

		int choice = 0;
		cin >> choice;

		if(choice != 1 && choice != 2)
		{
			cout << "\nInvalid choice" << endl;
			system("pause");
			system("cls");
			return;
		}

		for (int i = 0; i < this->m_workers_num; i++)
		{
			int min_or_max = i;
			for (int j = i + 1; j < this->m_workers_num; j++)
			{
				if (choice == 1)
				{
					if (this->m_workers[min_or_max]->m_Id > this->m_workers[j]->m_Id)
					{
						min_or_max = j;
					}
				}
				else
				{
					if (this->m_workers[min_or_max]->m_Id < this->m_workers[j]->m_Id)
					{
						min_or_max = j;
					}
				}
			}
			//�ж�һ��ʼ�϶������ֵ����Сֵ���ǲ��Ǽ�������ֵ����Сֵ
			//��������򽻻�����
			if (i != min_or_max)
			{
				Worker* temp = this->m_workers[i];
				this->m_workers[i] = this->m_workers[min_or_max];
				this->m_workers[min_or_max] = temp;
			}
		}
		cout << "\nSort successfully!" << endl;
		this->Save();
		this->ShowWorkers();
	}
}

void WorkerManager::ClearWorkers()
{
	cout << "\nConfirm emptying?" << endl;
	cout << "1��Yes" << endl;
	cout << "2��Back" << endl;
	
	int choice = 0;
	cin >> choice;

	if (choice == 1)
	{
		//ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		
		if (this->m_workers != NULL)
		{
			//ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_workers_num; i++)
			{
				delete this->m_workers[i];
				this->m_workers[i] = NULL;
			}
			//ɾ����������ָ��
			delete[] this->m_workers;
			this->m_workers = NULL;
			this->m_workers_num = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "\nClear successfully!" << endl;
	}
	else if (choice == 2)
	{
		system("cls");
	}
	else
	{
		cout << "\nInvalid choice" << endl;
		system("pause");
		system("cls");
	}
}

WorkerManager::~WorkerManager()
{
	if (this->m_workers != NULL)
	{
		for (int i = 0; i < this->m_workers_num; i++)
		{
			if (this->m_workers[i] != NULL)
			{
				delete this->m_workers[i];
				this->m_workers[i] = NULL;
			}
		}
		
		delete[] this->m_workers;
		this->m_workers = NULL;
	}
}