#ifndef PAGE_QUIT_H
#define PAGE_QUIT_H

#include "Page.h"

namespace ccs
{
	class PageQuit : public Page {
	public:
		PageQuit();
		PageQuit(const string title);
		PageQuit(const int index);
		PageQuit(const string title, const int index);
		PageQuit(const int index, const string title);
		~PageQuit();
	public:
		void SetTitle(string title);
		void Show();
		EPage WaitInput();
	};
}

#endif // ! PAGE_QUIT_H