#include "PageWelcome.h"
using namespace ccs;

PageWelcome::PageWelcome() : Page()
{
	this->title = "Welcome!";
}

PageWelcome::PageWelcome(const string title) : Page(title) {}

PageWelcome::PageWelcome(const int index) : Page(index)
{
	this->title = "Welcome!";
}

PageWelcome::PageWelcome(const string title, const int index) : Page(title, index) {}

PageWelcome::PageWelcome(const int index, const string title) : Page(index, title) {}

PageWelcome::~PageWelcome() {}

void PageWelcome::SetTitle(string title)
{
	this->title = title;
}
void PageWelcome::Show()
{
	system("cls");
	cout << _TITLE << ": " << this->title << " " << _INDEX << ": " << this->pageIndex << endl;
	cout << _FULL_LINE << endl;
	cout << "                                    " << "»¶Ó­Ê¹ÓÃ" << endl;
	cout << "                                  " << _APP_NAME << endl;
	cout << endl << _FULL_LINE << endl;
}

EPage PageWelcome::WaitInput()
{
	system("pause");
	EPage nextPage = E_PAGE_MAIN_MENU;
	return nextPage;
}