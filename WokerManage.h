#pragma once
#include <iostream>
#include "Worker.h"
#include <fstream>
#define FILENAME "Data.txt"
using namespace std;
//主菜单
class WorkerManage
{
public:
	Worker ** m_worker;//指向work *的堆区空间
	int m_Num;//员工总数
	bool m_FileEmpty;//文件是否为空
	WorkerManage();
	void ChangeWorker();//修改
	void FindWorker();//查找
	void SortWorker();//排序
	void Clear();//清空文件
	void ShowMenu();//展示菜单
	int GetNum();//获取职工人数
	void InitWork();//初始化
	void AddWorker();//添加员工
	void DeleteWorker();//删除员工
	void ExitSystem();//退出功能
	void ShowWorkers();//展示员工
	int IsExit(int id);//判断员工是否存在
	void SavaData();//保存到电脑中
	~WorkerManage();
};