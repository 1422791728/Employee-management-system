#include "Worker.h"
Employee::Employee(int id, string name, int did) 
{
	m_id = id;
	m_name = name;
	m_did = did;
}
string Employee::GetDepartname()//��ȡ��������
{
	return string("Ա��");
}
void Employee::Show()//չʾ��Ϣ
{
	cout << "���" << m_id << "  "
		 << "����" << m_name << "  "
		 << "��������" << GetDepartname() << "  "
		 << "ָ��" << "��ɾ����õ�����" << endl;
}
Manage::Manage(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}
string Manage::GetDepartname()//��ȡ��������
{
	return string("����");
}
void Manage::Show()//չʾ��Ϣ
{
	cout << "���" << m_id << "  "
		<< "����" << m_name << "  "
		<< "��������" << GetDepartname() << "  "
		<< "ָ��" << "����ϰ岼�õ������ҷ��������Ա��" << endl;
}
Boss::Boss(int id, string name, int did)
{
	m_id = id;
	m_name = name;
	m_did = did;
}
string Boss::GetDepartname()//��ȡ��������
{
	return string("�ϰ�");
}
void Boss::Show()//չʾ��Ϣ
{
	cout << "���" << m_id << "  "
		<< "����" << m_name << "  "
		<< "��������" << GetDepartname() << "  "
		<< "ָ��" << "����ϰ岼�õ������ҷ��������Ա��" << endl;
}