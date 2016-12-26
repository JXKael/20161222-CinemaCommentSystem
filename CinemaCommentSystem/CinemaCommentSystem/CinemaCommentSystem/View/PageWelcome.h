#include "Page.h"

#ifndef PAGE_WELCOME_H
#define PAGE_WELCOME_H

class PageWelcome : public Page
{
public:
	PageWelcome();
	~PageWelcome();
protected:
	void SetTitle(string title);
	void Show();
	void WaitInput();
	void Input(const int input);
};

#endif