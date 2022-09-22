#pragma once
#include "Worker.h"
class Employee :public Worker 
{
public:
	Employee(int Id, string name, int DeptId);
	~Employee();

	//显示个人信息
	virtual void ShowInfo();
	//获取岗位名称
	virtual string GetDeptName();
};