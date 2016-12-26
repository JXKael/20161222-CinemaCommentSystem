#include "PageWelcome.h"

PageWelcome::PageWelcome() : Page()
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
	cout << _TITLE << ": " << this->title << endl;
	cout << _FULL_LINE << endl;
	cout << "                                    " << _WELCOME_USE << endl;
	cout << "                                  " << _APP_NAME << endl;
	cout << _FULL_LINE << endl;
	system("pause");

}
void PageWelcome::WaitInput()
{
	return;
}
void PageWelcome::Input(const int input)
{
	return;
}