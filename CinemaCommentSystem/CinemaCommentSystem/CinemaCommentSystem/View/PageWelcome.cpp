#include "PageWelcome.h"

PageWelcome::PageWelcome() : Page()
{
	this->title = "Welcome!";
}

PageWelcome::PageWelcome(const int index) : Page(index)
{
	this->title = "Welcome!";
}

PageWelcome::~PageWelcome()
{

}

void PageWelcome::SetTitle(string title)
{
	this->title = title;
}
void PageWelcome::Show()
{
	system("cls");
	cout << _TITLE << ": " << this->title << this->pageIndex << endl;
	cout << _FULL_LINE << endl;
	cout << "                                    " << "»¶Ó­Ê¹ÓÃ" << endl;
	cout << "                                  " << _APP_NAME << endl;
	cout << endl << _FULL_LINE << endl;
}

EPage PageWelcome::WaitInput()
{
	system("pause");
	EPage nextPage = E_PAGE_MAIN;
	return nextPage;
}