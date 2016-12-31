#include "PageManagerMenu.h"
using namespace ccs;

PageManagerMenu::PageManagerMenu() : Page()
{
	this->title = "Manager Menu";
}

PageManagerMenu::PageManagerMenu(const string title) : Page(title) {}

PageManagerMenu::PageManagerMenu(const int index) : Page(index)
{
	this->title = "Manager Menu";
}

PageManagerMenu::PageManagerMenu(const string title, const int index) : Page(title, index) {}

PageManagerMenu::PageManagerMenu(const int index, const string title) : Page(index, title) {}

PageManagerMenu::~PageManagerMenu() {}

void PageManagerMenu::SetTitle(string title)
{
	this->title = title;
}
void PageManagerMenu::Show()
{
	system("cls");
	cout << _TITLE << ": " << this->title << " " << _INDEX << ": " << this->pageIndex << endl;
	cout << _FULL_LINE << endl;
	cout << "1、添加电影" << endl;
	cout << "2、修改电影" << endl;
	cout << "3、删除电影" << endl;
	cout << "0、返回" << endl;
	cout << endl << _FULL_LINE << endl;
}

EPage PageManagerMenu::WaitInput()
{
	int input = 0;
	cout << _INPUT_NUM_WAIT_1;
	cin >> input;
	EPage nextPage;
	switch (input)
	{
	case 1: nextPage = E_PAGE_MAIN_MENU; break;
	case 2: nextPage = E_PAGE_MAIN_MENU; break;
	case 3: nextPage = E_PAGE_MAIN_MENU; break;
	case 0: nextPage = E_BACK; break;
	default: break;
	}
	return nextPage;
}