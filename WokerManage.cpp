#include "WokerManage.h"
WorkerManage::WorkerManage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		m_Num = 0;
		m_worker = NULL;
		m_FileEmpty = true;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		m_Num = 0;
		m_worker = NULL;
		m_FileEmpty = true;
		return;
	}
	int num = GetNum();
	cout << "ԭְ������" << num << endl;
	m_Num = num;
	m_worker = new Worker * [m_Num];
	InitWork();
	m_FileEmpty = false;
	/*for (int i = 0; i < m_Num; i++)
	{
		cout << m_worker[i]->m_id << endl;
	}*/

}
void WorkerManage::ShowMenu()//չʾ�˵�
{
	cout << "��ӭʹ��ְ������ϵͳ" << endl;
	cout << "0���˳��������" << endl;
	cout << "1������ְ����Ϣ" << endl;
	cout << "2����ʾְ����Ϣ" << endl;
	cout << "3��ɾ����ְְ����Ϣ" << endl;
	cout << "4���޸�ְ����Ϣ" << endl;
	cout << "5������ְ����Ϣ" << endl;
	cout << "6�����ձ������" << endl;
	cout << "7����������ĵ�" << endl;
	cout << endl;

}
void WorkerManage::Clear()
{
	if (m_FileEmpty)
	{
		cout << "�ļ�������" << endl;
	}
	else
	{
		cout << "ȷ��ɾ����" << endl;
		cout << "1.ȷ��" << endl;
		cout << "2.����" << endl;
		int select;
		cin >> select;
		if (select == 1)
		{
			ofstream ofs(FILENAME,ios::trunc);
			ofs.close();
			if (m_worker != NULL)
			{
				for (int i = 0; i < m_Num; i++)
				{
					delete m_worker[i];
					m_worker[i] = NULL;
				}
				delete[] m_worker;
				m_Num = 0;
				m_worker = NULL;
				m_FileEmpty = true;
				cout << "����ɹ�" << endl;
			}
		}
	}
	system("pause");
	system("cls");
}
void  WorkerManage::ChangeWorker()
{
	if (m_FileEmpty)
	{
		cout << "�ļ�������" << endl;
		
	}
	else
	{
		cout << "������Ҫ�޸ĵĳ�ԱID" << endl;
		int id;
		cin >> id;
		int ret = IsExit(id);
		if (ret != -1)
		{
			cout << "ְ������" << endl;
			delete m_worker[ret];
			int newid;
			string newname;
			int newdid;
			cout << "�������µı��" << endl;
			cin >> newid;
			cout << "�������µ�����" << endl;
			cin >> newname;
			cout << "��ѡ���µĲ���" << endl;
			cin >> newdid;
			switch (newdid)
			{
			case 1:
				m_worker[ret] = new Employee(newid, newname, newdid);
				break;
			case 2:
				m_worker[ret] = new Manage(newid, newname, newdid);
				break;
			case 3:
				m_worker[ret] = new Boss(newid, newname, newdid);
				break;
			default:
				break;
			}
			cout << "�޸ĳɹ�" << endl;
			SavaData();
		}
		else
		{
			cout << "�޸�ʧ��" << endl;
		}
	}
	system("pause");
	system("cls");

}
void WorkerManage::ExitSystem()//�˳�����
{
	system("cls");
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void WorkerManage::AddWorker()
{
	cout << "������Ҫ��ӵ�Ա������" << endl;
	int Addnum;
	cin >> Addnum;
	if(Addnum > 0)
	{ 
		int newsize = Addnum + this->m_Num;
		Worker** newwork = new Worker * [newsize];
		if (m_worker != NULL)
		{
			for (int i = 0; i < m_Num; i++)
			{
				newwork[i] = m_worker[i];
			}
		}
		for (int i = 0; i < Addnum; i++)
		{
			int id;
			string name;
			int did;
			cout << "��" << i + 1 << "��Ա���ı��" << endl;
			cin >> id;
			cout << "��" << i + 1 << "��Ա��������" << endl;
			cin >> name;

			cout << "1 Ա��" << endl;
			cout << "2 ����" << endl;
			cout << "3 �ϰ�" << endl;
			cout << "ѡ��" << i + 1 << "��Ա����ְλ" << endl;
			cin >> did;
			Worker* work = NULL;
			switch (did)
			{
			case 1:
				work = new Employee(id,name,did);
				break;
			case 2:
				work = new Manage(id, name, did);
				break;
			case 3:
				work = new Boss(id, name, did);
				break;
			default:
				cout << "����Υ��" << endl;
				break;
			}
			newwork[i + m_Num] = work;
		}
		delete[] m_worker;
		m_Num = newsize;
		m_worker = newwork;
		cout << "���" << Addnum<<"��Ա���ɹ�" << endl;
		SavaData();
		m_FileEmpty = false;
	}
	else
	{
		cout << "����Υ��" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManage::DeleteWorker()//ɾ��Ա��
{
	if (m_FileEmpty)
	{
		cout << "û���κ�Ա��" << endl;
	}
	else
	{
		int id;
		cout << "������Ҫɾ���ı��" << endl;
		cin >> id;
		int index = IsExit(id);
		if (index == -1)
		{
			cout << "Ա��������" << endl;
		}
		else
		{
			for (int i = index; i < m_Num - 1; i++)
			{
				m_worker[i] = m_worker[i + 1];
			}
			m_Num--;
			SavaData();
			cout << "ɾ���ɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManage::ShowWorkers()//չʾԱ��
{
	if (m_FileEmpty)
	{
		cout << "�޼�¼Ա��" << endl;
	}
	else
	{
		for (int i = 0; i < m_Num; i++)
		{
			m_worker[i]->Show();
		}
	}
	system("pause");
	system("cls");
}
void WorkerManage::SortWorker()//����
{
	if (m_FileEmpty)
	{
		cout << "�ļ�Ϊ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��ѡ������ʽ" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	int select;
	cin >> select;
	for (int i = 0; i < m_Num; i++)
	{
		int minOrmax = i;
		for (int j = i + 1; j < m_Num; j++)
		{
			if (select == 1)
			{
				if (m_worker[minOrmax]->m_id > m_worker[j]->m_id)
				{
					minOrmax = j;
				}
			}
			else if (select == 2)
			{
				if (m_worker[minOrmax]->m_id < m_worker[j]->m_id)
				{
					minOrmax = j;
				}
			}
		}
		if (minOrmax != i)
		{
			Worker* worker = m_worker[minOrmax];
			m_worker[minOrmax] = m_worker[i];
			m_worker[i] = worker;
		}
	}
	SavaData();
	ShowWorkers();
	
}
void WorkerManage::FindWorker()
{
	if (m_FileEmpty)
	{
		cout << "�ļ�Ϊ��" << endl;
	}
	else
	{
		int select;
		cout << "1.����Ų���" << endl;
		cout << "2.����������" << endl;
		cout << "��ѡ����ҷ�ʽ" << endl;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "������Ҫ���ҵı��" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1)
			{
				cout << "���ҳɹ�" << endl;
				cout << "ְ����Ϣ����" << endl;
				m_worker[ret]->Show();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "������Ҫ���ҵ�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_Num; i++)
			{
				if (name == m_worker[i]->m_name)
				{
					cout << "��ְ������,��Ϣ����" << endl;
					m_worker[i]->Show();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "�Բ�����޴���" << endl;
			}
		}
		else
		{
			cout << "������������������" << endl;
		}
		system("pause");
		system("cls");
		
	}
}
int WorkerManage::IsExit(int id)//�ж�Ա���Ƿ����
{
	int index = -1;
	for (int i = 0; i < m_Num; i++)
	{
		if (m_worker[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManage::SavaData()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < m_Num; i++)
	{
		ofs << m_worker[i]->m_id << " "
			<< m_worker[i]->m_name << " "
			<< m_worker[i]->m_did << endl;
	}
	ofs.close();
}
int WorkerManage::GetNum()//��ȡְ������
{
	int id;
	string name;
	int did;
	ifstream ifs;
	ifs.open(FILENAME,ios::in);
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		num++;
	}
	ifs.close();
	return num;
}
void WorkerManage::InitWork()//��ʼ��
{
	int id;
	string name;
	int did; 
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id,name,did);
		}
		else if (did == 2)
		{
			worker = new Manage(id, name, did);
		}
		else 
		{
			worker = new Boss(id, name, did);
		}
		m_worker[index++] = worker;
	}
}
WorkerManage::~WorkerManage()
{
	if (m_worker != NULL)
	{
		delete[] m_worker;
		m_worker = NULL;
	}
}
