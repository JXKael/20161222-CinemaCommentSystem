#ifndef PAGE_WELCOME_H
#define PAGE_WELCOME_H

#include "Page.h"

namespace ccs
{
	class PageWelcome : public Page {
	public:
		PageWelcome();
		PageWelcome(const int index);
		~PageWelcome();
	protected:
		void SetTitle(string title);
		void Show();
		EPage WaitInput();
	};
}

using namespace ccs;

#endif