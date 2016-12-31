#include "PageMainMenu.h"
using namespace ccs;

PageMainMenu::PageMainMenu() : Page()
{
	this->title = "Main Menu";
}

PageMainMenu::PageMainMenu(const string title) : Page(title) {}

PageMainMenu::PageMainMenu(const int index) : Page(index)
{
	this->title = "Main Menu";
}

PageMainMenu::PageMainMenu(const string title, const int index) : Page(title, index) {}

PageMainMenu::PageMainMenu(const int index, const string title) : Page(index, title) {}

PageMainMenu::~PageMainMenu() {}

void PageMainMenu::SetTitle(string title)
{
	this->title = title;
}
void PageMainMenu::Show()
{
	system("cls");
	cout << _TITLE << ": " << this->title << " " <<_INDEX << ": " << this->pageIndex << endl;
	cout << _FULL_LINE << endl;
	cout << "1、普通用户" << endl;
	cout << "2、管理员功能（需验证）" << endl;
	cout << "0、退出" << endl;
	cout << endl << _FULL_LINE << endl;
}

EPage PageMainMenu::WaitInput()
{
	int input = 0;
	cout << _INPUT_NUM_WAIT_1;
	cin >> input;
	EPage nextPage;
	switch (input)
	{
	case 1: nextPage = E_PAGE_NORMAL_USER_MENU; break;
	case 2: nextPage = E_PAGE_MANAGER_MENU; break;
	case 0: nextPage = E_PAGE_QUIT; break;
	default: break;
	}
	return nextPage;
}