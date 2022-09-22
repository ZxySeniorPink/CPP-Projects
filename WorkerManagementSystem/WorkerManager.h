#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"

#define FILENAME "worker_file.txt"

using namespace std;

class WorkerManager
{
public:

	Worker** m_workers;//ְ��ָ������

	int m_workers_num; //ְ������

	bool m_FileIsEmpty;//�ж��ļ��Ƿ�Ϊ�� ��־

	WorkerManager();

	~WorkerManager();

	void ShowMenu();                  //��ʾ�˵�
	
	void ExitSystem();				  //�˳�ϵͳ

	void InitWorker();				  //��ʼ��Ա��
	
	void AddWorker();                 //���Ա����Ϣ
	
	void Save();					  //�����ļ���Ϣ
	
	int GetWorkersNum();			  //ͳ���ļ�����

	void ShowWorkers();				  //��ʾԱ����Ϣ

	int IsExist(int id);			  //Ա���Ƿ����

	void DeleteWorker();			  //ɾ��Ա����Ϣ

	void ModifyWorker();			  //�޸�Ա����Ϣ

	void FindWorker();				  //����Ա����Ϣ

	void SortWorkers();				  //��ID����Ա��

	void ClearWorkers();			  //���Ա����Ϣ


};
