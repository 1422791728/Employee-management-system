#include <iostream>
#include "WokerManage.h"
using namespace std;
int main()
{

	WorkerManage wk;
	while (1)
	{
		wk.ShowMenu();
		int choice;
		cout << "请输入要选择的功能" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			wk.ExitSystem();
			break;
		case 1:
			wk.AddWorker();
			break;
		case 2:
			wk.ShowWorkers();
			break;
		case 3:
			wk.DeleteWorker();
			break;
		case 4:
			wk.ChangeWorker();
			break;
		case 5:
			wk.FindWorker();
			break;
		case 6:
			wk.SortWorker();
			break;
		case 7:
			wk.Clear();
			break;
		default:
			system("cls");
			break;
		}
	}
	
}
