#pragma once
#include "Worker.h"
class Employee :public Worker 
{
public:
	Employee(int Id, string name, int DeptId);
	~Employee();

	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};