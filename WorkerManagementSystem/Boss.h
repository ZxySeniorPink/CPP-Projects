#pragma once
#include "Worker.h"
class Boss :public Worker
{
public:
	Boss(int Id, string name, int DeptId);
	~Boss();

	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string GetDeptName();
};