#pragma once
#include "Worker.h"
class Manager :public Worker
{
public:
	Manager(int Id, string name, int DeptId);
	~Manager();

	//显示个人信息
	virtual void ShowInfo();
	//获取岗位名称
	virtual string GetDeptName();
};