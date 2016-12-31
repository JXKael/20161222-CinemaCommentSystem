#include "PageQuit.h"
using namespace ccs;

PageQuit::PageQuit() : Page()
{
	this->title = "Quit";
}

PageQuit::PageQuit(const string title) : Page(title) {}

PageQuit::PageQuit(const int index) : Page(index)
{
	this->title = "Quit";
}

PageQuit::PageQuit(const string title, const int index) : Page(title, index) {}

PageQuit::PageQuit(const int index, const string title) : Page(index, title) {}

PageQuit::~PageQuit() {}

void PageQuit::SetTitle(string title)
{
	this->title = title;
}
void PageQuit::Show()
{
	system("cls");
	cout << _TITLE << ": " << this->title << " " << _INDEX << ": " << this->pageIndex << endl;
	cout << _FULL_LINE << endl;
	cout << "                                    " << "Ð»Ð»Ê¹ÓÃ" << endl;
	cout << endl << _FULL_LINE << endl;
}

EPage PageQuit::WaitInput()
{
	system("pause");
	EPage nextPage = E_QUIT;
	return nextPage;
}