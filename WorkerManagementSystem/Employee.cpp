#include "Employee.h"

Employee::Employee(int Id, string name, int DeptId)
{
	this->m_Id = Id;
	this->m_Name = name;
	this->m_DeptId = DeptId;
}

Employee::~Employee()
{

}

void Employee::ShowInfo()
{
	cout << "\nEmployee No: " << this->m_Id
		 << "\tEmployee Name: " << this->m_Name
		 << "\tPost: " << this->GetDeptName()
		 << "\tResponsibilities: Complete the tasks assigned by the manager" << endl;
}

string Employee::GetDeptName()
{
	return (string)"Employee";
}
