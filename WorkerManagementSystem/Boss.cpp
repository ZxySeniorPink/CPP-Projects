#include "Boss.h"

Boss::Boss(int Id, string name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

Boss::~Boss()
{

}

void Boss::ShowInfo()
{
	cout << "\nEmployee No: " << this->m_Id
		 << "\tEmployee Name: " << this->m_Name
		 << "\tPost: " << this->GetDeptName()
		 << "\tResponsibilities: Manage all affairs of the company" << endl;
}

string Boss::GetDeptName()
{
	return (string)"Boss";
}

