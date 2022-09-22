#include "Manager.h"
Manager::Manager(int Id, string name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

Manager::~Manager()
{

}

void Manager::ShowInfo()
{
	cout << "\nEmployee No: " << this->m_Id
		 << "\tEmployee Name: " << this->m_Name
		 << "\tPost: " << this->GetDeptName()
		 << "\tResponsibilities: Complete the tasks assigned by the boss and issue them to the employees" << endl;
}

string Manager::GetDeptName()
{
	return (string)"Manager";
}