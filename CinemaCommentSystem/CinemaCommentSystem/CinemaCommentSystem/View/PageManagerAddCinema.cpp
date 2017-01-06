#include "PageManagerAddCinema.h"
using namespace ccs;

PageManagerAddCinema::PageManagerAddCinema() : Page()
{
	this->title = "Manager Add Cinema";
}

PageManagerAddCinema::PageManagerAddCinema(const string title) : Page(title) {}

PageManagerAddCinema::PageManagerAddCinema(const int index) : Page(index)
{
	this->title = "Manager Add Cinema";
}

PageManagerAddCinema::PageManagerAddCinema(const string title, const int index) : Page(title, index) {}

PageManagerAddCinema::PageManagerAddCinema(const int index, const string title) : Page(index, title) {}

PageManagerAddCinema::~PageManagerAddCinema() {}

void PageManagerAddCinema::SetTitle(string title)
{
	this->title = title;
}
void PageManagerAddCinema::Show()
{
	system("cls");
	cout << _TITLE << ": " << this->title << " " << _INDEX << ": " << this->pageIndex << endl;
	cout << _FULL_LINE << endl;
	cout << "I> 电影名称" << endl;
	cout << "0、返回" << endl;
	cout << endl << _FULL_LINE << endl;
}

EPage PageManagerAddCinema::WaitInput()
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