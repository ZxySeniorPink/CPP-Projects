#pragma once
#include "Worker.h"
class Boss :public Worker
{
public:
	Boss(int Id, string name, int DeptId);
	~Boss();

	//显示个人信息
	virtual void ShowInfo();
	//获取岗位名称
	virtual string GetDeptName();
};