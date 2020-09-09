#include "Worker.h"
Employee::Employee(int id, string name, int did) 
{
	m_id = id;
	m_name = name;
	m_did = did;
}
string Employee::GetDepartname()//获取部门名称
{
	return string("员工");
}
void Employee::Show()//展示信息
{
	cout << "编号" << m_id << "  "
		 << "姓名" << m_name << "  "
		 << "部门名称" << GetDepartname() << "  "
		 << "指责" << "完成经理布置的任务" << endl;
}
Manage::Manage(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}
string Manage::GetDepartname()//获取部门名称
{
	return string("经理");
}
void Manage::Show()//展示信息
{
	cout << "编号" << m_id << "  "
		<< "姓名" << m_name << "  "
		<< "部门名称" << GetDepartname() << "  "
		<< "指责" << "完成老板布置的任务并且发布任务给员工" << endl;
}
Boss::Boss(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}
string Boss::GetDepartname()//获取部门名称
{
	return string("老板");
}
void Boss::Show()//展示信息
{
	cout << "编号" << m_id << "  "
		<< "姓名" << m_name << "  "
		<< "部门名称" << GetDepartname() << "  "
		<< "指责" << "完成老板布置的任务并且发布任务给员工" << endl;
}