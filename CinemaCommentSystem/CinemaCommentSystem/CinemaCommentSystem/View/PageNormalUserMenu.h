#ifndef PAGE_NORMAL_USER_MENU_H
#define PAGE_NORMAL_USER_MENU_H

#include "Page.h"

namespace ccs
{
	class PageNormalUserMenu : public Page {
	public:
		PageNormalUserMenu();
		PageNormalUserMenu(const string title);
		PageNormalUserMenu(const int index);
		PageNormalUserMenu(const string title, const int index);
		PageNormalUserMenu(const int index, const string title);
		~PageNormalUserMenu();
	public:
		void SetTitle(string title);
		void Show();
		EPage WaitInput();
	};
}

#endif // ! PAGE_NORMAL_USER_MENU_H