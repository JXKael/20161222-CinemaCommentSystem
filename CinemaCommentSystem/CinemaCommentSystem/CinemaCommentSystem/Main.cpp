#include "Main.h"
using namespace std;

void AddList(LinkList<int> *);

void main()
{
	int b = -2;
	LinkList<int> *list = new LinkList<int>(b);
	cout << *list << endl;

	AddList(list);
	cout << "增加列表：" << *list << endl;

	/*list->Insert(5, -1);
	cout << "插入-1：" << *list << endl;*/

	list->ModifyAt(2, -3);
	cout << "修改：" << *list << endl;

	list->Clear();
	cout << "清空：" << *list << endl;

	system("Pause");
}

void AddList(LinkList<int> *list)
{
	int a = 0, b = 1, c = 2, d = 3;
	list->Add(a);
	list->Add(b);
	list->Add(c);
	list->Add(d);
}