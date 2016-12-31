#ifndef PAGE_MAIN_MENU_H
#define PAGE_MAIN_MENU_H

#include "Page.h"

namespace ccs
{
	class PageMainMenu : public Page {
	public:
		PageMainMenu();
		PageMainMenu(const string title);
		PageMainMenu(const int index);
		PageMainMenu(const string title, const int index);
		PageMainMenu(const int index, const string title);
		~PageMainMenu();
	public:
		void SetTitle(string title);
		void Show();
		EPage WaitInput();
	};
}

#endif // ! PAGE_MAIN_MENU_H