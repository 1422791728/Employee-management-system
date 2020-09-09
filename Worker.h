#pragma once
#include <iostream>
#include <string>
using namespace std;
class Worker
{
public:
	int m_id;
	string m_name;
	int m_did;
public:
	virtual string GetDepartname() = 0;//获取部门名称
	virtual void Show() = 0;//展示信息
};
class Employee : public Worker
{
public:
	Employee(int id,string name,int did);
	virtual string GetDepartname();//获取部门名称
	virtual void Show();//展示信息
};
class Manage : public Worker
{
public:
	Manage(int id, string name, int did);
	virtual string GetDepartname();//获取部门名称
	virtual void Show();//展示信息
};

class Boss : public Worker
{
public:
	Boss(int id, string name, int did);
	virtual string GetDepartname();//获取部门名称
	virtual void Show();//展示信息
};

