#ifndef PAGE_MANAGER_MENU_H
#define PAGE_MANAGER_MENU_H

#include "Page.h"

namespace ccs
{
	class PageManagerMenu : public Page {
	public:
		PageManagerMenu();
		PageManagerMenu(const string title);
		PageManagerMenu(const int index);
		PageManagerMenu(const string title, const int index);
		PageManagerMenu(const int index, const string title);
		~PageManagerMenu();
	public:
		void SetTitle(string title);
		void Show();
		EPage WaitInput();
	};
}

#endif // ! PAGE_MANAGER_MENU_H