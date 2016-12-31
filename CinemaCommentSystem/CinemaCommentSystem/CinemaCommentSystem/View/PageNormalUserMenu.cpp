#include "PageNormalUserMenu.h"
using namespace ccs;

PageNormalUserMenu::PageNormalUserMenu() : Page()
{
	this->title = "Normal User Menu";
}

PageNormalUserMenu::PageNormalUserMenu(const string title) : Page(title) {}

PageNormalUserMenu::PageNormalUserMenu(const int index) : Page(index)
{
	this->title = "Normal User Menu";
}

PageNormalUserMenu::PageNormalUserMenu(const string title, const int index) : Page(title, index) {}

PageNormalUserMenu::PageNormalUserMenu(const int index, const string title) : Page(index, title) {}

PageNormalUserMenu::~PageNormalUserMenu() {}

void PageNormalUserMenu::SetTitle(string title)
{
	this->title = title;
}
void PageNormalUserMenu::Show()
{
	system("cls");
	cout << _TITLE << ": " << this->title << " " << _INDEX << ": " << this->pageIndex << endl;
	cout << _FULL_LINE << endl;
	cout << "1、查找电影" << endl;
	cout << "0、返回" << endl;
	cout << endl << _FULL_LINE << endl;
}

EPage PageNormalUserMenu::WaitInput()
{
	int input = 0;
	cout << _INPUT_NUM_WAIT_1;
	cin >> input;
	EPage nextPage;
	switch (input)
	{
		case 1: nextPage = E_PAGE_NORMAL_USER_MENU; break;
		case 0: nextPage = E_BACK; break;
		default: break;
	}
	return nextPage;
}