#pragma once
#include <iostream>
#include "Worker.h"
#include <fstream>
#define FILENAME "Data.txt"
using namespace std;
//���˵�
class WorkerManage
{
public:
	Worker ** m_worker;//ָ��work *�Ķ����ռ�
	int m_Num;//Ա������
	bool m_FileEmpty;//�ļ��Ƿ�Ϊ��
	WorkerManage();
	void ChangeWorker();//�޸�
	void FindWorker();//����
	void SortWorker();//����
	void Clear();//����ļ�
	void ShowMenu();//չʾ�˵�
	int GetNum();//��ȡְ������
	void InitWork();//��ʼ��
	void AddWorker();//���Ա��
	void DeleteWorker();//ɾ��Ա��
	void ExitSystem();//�˳�����
	void ShowWorkers();//չʾԱ��
	int IsExit(int id);//�ж�Ա���Ƿ����
	void SavaData();//���浽������
	~WorkerManage();
};