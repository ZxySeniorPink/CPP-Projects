#pragma once
#include "Worker.h"
class Manager :public Worker
{
public:
	Manager(int Id, string name, int DeptId);
	~Manager();

	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};