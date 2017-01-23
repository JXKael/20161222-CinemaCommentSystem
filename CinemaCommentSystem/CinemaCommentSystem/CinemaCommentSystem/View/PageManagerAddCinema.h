#ifndef PAGE_MANAGER_ADD_CINEMA
#define PAGE_MANAGER_ADD_CINEMA

#include "Page.h"

namespace ccs
{
	class PageManagerAddCinema : public Page {
	public:
		PageManagerAddCinema();
		PageManagerAddCinema(const string title);
		PageManagerAddCinema(const int index);
		PageManagerAddCinema(const string title, const int index);
		PageManagerAddCinema(const int index, const string title);
		~PageManagerAddCinema();
	public:
		void SetTitle(string title);
		void Show();
		EPage WaitInput();
	};
}

#endif // ! PAGE_MANAGER_ADD_CINEMA