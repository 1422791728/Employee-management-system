#include "WokerManage.h"
WorkerManage::WorkerManage()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		m_Num = 0;
		m_worker = NULL;
		m_FileEmpty = true;
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		m_Num = 0;
		m_worker = NULL;
		m_FileEmpty = true;
		return;
	}
	int num = GetNum();
	cout << "原职工人数" << num << endl;
	m_Num = num;
	m_worker = new Worker * [m_Num];
	InitWork();
	m_FileEmpty = false;
	/*for (int i = 0; i < m_Num; i++)
	{
		cout << m_worker[i]->m_id << endl;
	}*/

}
void WorkerManage::ShowMenu()//展示菜单
{
	cout << "欢迎使用职工管理系统" << endl;
	cout << "0、退出管理程序" << endl;
	cout << "1、增加职工信息" << endl;
	cout << "2、显示职工信息" << endl;
	cout << "3、删除离职职工信息" << endl;
	cout << "4、修改职工信息" << endl;
	cout << "5、查找职工信息" << endl;
	cout << "6、按照编号排序" << endl;
	cout << "7、清空所有文档" << endl;
	cout << endl;

}
void WorkerManage::Clear()
{
	if (m_FileEmpty)
	{
		cout << "文件不存在" << endl;
	}
	else
	{
		cout << "确定删除？" << endl;
		cout << "1.确定" << endl;
		cout << "2.返回" << endl;
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
				cout << "清除成功" << endl;
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
		cout << "文件不存在" << endl;
		
	}
	else
	{
		cout << "请输入要修改的成员ID" << endl;
		int id;
		cin >> id;
		int ret = IsExit(id);
		if (ret != -1)
		{
			cout << "职工存在" << endl;
			delete m_worker[ret];
			int newid;
			string newname;
			int newdid;
			cout << "请输入新的编号" << endl;
			cin >> newid;
			cout << "请输入新的名字" << endl;
			cin >> newname;
			cout << "请选择新的部门" << endl;
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
			cout << "修改成功" << endl;
			SavaData();
		}
		else
		{
			cout << "修改失败" << endl;
		}
	}
	system("pause");
	system("cls");

}
void WorkerManage::ExitSystem()//退出功能
{
	system("cls");
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void WorkerManage::AddWorker()
{
	cout << "请输入要添加的员工数量" << endl;
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
			cout << "第" << i + 1 << "个员工的编号" << endl;
			cin >> id;
			cout << "第" << i + 1 << "个员工的姓名" << endl;
			cin >> name;

			cout << "1 员工" << endl;
			cout << "2 经理" << endl;
			cout << "3 老板" << endl;
			cout << "选择" << i + 1 << "个员工的职位" << endl;
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
				cout << "输入违法" << endl;
				break;
			}
			newwork[i + m_Num] = work;
		}
		delete[] m_worker;
		m_Num = newsize;
		m_worker = newwork;
		cout << "添加" << Addnum<<"名员工成功" << endl;
		SavaData();
		m_FileEmpty = false;
	}
	else
	{
		cout << "输入违法" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManage::DeleteWorker()//删除员工
{
	if (m_FileEmpty)
	{
		cout << "没有任何员工" << endl;
	}
	else
	{
		int id;
		cout << "请输入要删除的编号" << endl;
		cin >> id;
		int index = IsExit(id);
		if (index == -1)
		{
			cout << "员工不存在" << endl;
		}
		else
		{
			for (int i = index; i < m_Num - 1; i++)
			{
				m_worker[i] = m_worker[i + 1];
			}
			m_Num--;
			SavaData();
			cout << "删除成功" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManage::ShowWorkers()//展示员工
{
	if (m_FileEmpty)
	{
		cout << "无记录员工" << endl;
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
void WorkerManage::SortWorker()//排序
{
	if (m_FileEmpty)
	{
		cout << "文件为空" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请选择排序方式" << endl;
	cout << "1.升序" << endl;
	cout << "2.降序" << endl;
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
		cout << "文件为空" << endl;
	}
	else
	{
		int select;
		cout << "1.按编号查找" << endl;
		cout << "2.按姓名查找" << endl;
		cout << "请选择查找方式" << endl;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入要查找的编号" << endl;
			cin >> id;
			int ret = IsExit(id);
			if (ret != -1)
			{
				cout << "查找成功" << endl;
				cout << "职工信息如下" << endl;
				m_worker[ret]->Show();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入要查找的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_Num; i++)
			{
				if (name == m_worker[i]->m_name)
				{
					cout << "该职工存在,信息如下" << endl;
					m_worker[i]->Show();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "对不起查无此人" << endl;
			}
		}
		else
		{
			cout << "输入有误，请重新输入" << endl;
		}
		system("pause");
		system("cls");
		
	}
}
int WorkerManage::IsExit(int id)//判断员工是否存在
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
int WorkerManage::GetNum()//获取职工人数
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
void WorkerManage::InitWork()//初始化
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
