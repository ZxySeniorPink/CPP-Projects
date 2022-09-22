#pragma once
#include <iostream>
#include <string>

using namespace std;

class Worker
{
public:

	//显示个人信息
	virtual void ShowInfo() = 0;
	//获取岗位名称
	virtual string GetDeptName() = 0;

//private:

	int m_Id;
	string m_Name;
	int m_DeptId;
};
