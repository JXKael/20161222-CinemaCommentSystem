#ifndef PAGE_WELCOME_H
#define PAGE_WELCOME_H

#include "Page.h"

namespace ccs
{
	class PageWelcome : public Page {
	public:
		PageWelcome();
		PageWelcome(const string title);
		PageWelcome(const int index);
		PageWelcome(const string title, const int index);
		PageWelcome(const int index, const string title);
		~PageWelcome();
	public:
		void SetTitle(string title);
		void Show();
		EPage WaitInput();
	};
}

#endif // ! PAGE_WELCOME_H