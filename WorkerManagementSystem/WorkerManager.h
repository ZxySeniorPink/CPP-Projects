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

	Worker** m_workers;//职工指针数组

	int m_workers_num; //职工人数

	bool m_FileIsEmpty;//判断文件是否为空 标志

	WorkerManager();

	~WorkerManager();

	void ShowMenu();                  //显示菜单
	
	void ExitSystem();				  //退出系统

	void InitWorker();				  //初始化员工
	
	void AddWorker();                 //添加员工信息
	
	void Save();					  //保存文件信息
	
	int GetWorkersNum();			  //统计文件人数

	void ShowWorkers();				  //显示员工信息

	int IsExist(int id);			  //员工是否存在

	void DeleteWorker();			  //删除员工信息

	void ModifyWorker();			  //修改员工信息

	void FindWorker();				  //查找员工信息

	void SortWorkers();				  //按ID排序员工

	void ClearWorkers();			  //清空员工信息


};
