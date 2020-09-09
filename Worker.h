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
	virtual string GetDepartname() = 0;//��ȡ��������
	virtual void Show() = 0;//չʾ��Ϣ
};
class Employee : public Worker
{
public:
	Employee(int id,string name,int did);
	virtual string GetDepartname();//��ȡ��������
	virtual void Show();//չʾ��Ϣ
};
class Manage : public Worker
{
public:
	Manage(int id, string name, int did);
	virtual string GetDepartname();//��ȡ��������
	virtual void Show();//չʾ��Ϣ
};

class Boss : public Worker
{
public:
	Boss(int id, string name, int did);
	virtual string GetDepartname();//��ȡ��������
	virtual void Show();//չʾ��Ϣ
};

