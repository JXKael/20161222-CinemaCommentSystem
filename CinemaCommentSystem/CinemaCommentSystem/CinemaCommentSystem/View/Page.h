#ifndef PAGE_H
#define PAGE_H

#include <iostream>
#include <string>
#include <cstddef>
#include "..\Data\ParameterString.h"
using namespace std;

namespace ccs
{
	enum EPage {
		E_PAGE_WELCOME,
		E_PAGE_MAIN_MENU,
		E_PAGE_NORMAL_USER_MENU,
		E_PAGE_MANAGER_MENU,
		E_PAGE_QUIT,
		E_QUIT,
		E_BACK
	};

	class Page {
	public:
		Page() : title(""), pageIndex(0) {}
		Page(const string title) : title(title), pageIndex(0) {}
		Page(const int index) : title(""), pageIndex(index) {}
		Page(const string title, const int index) : title(title), pageIndex(index) {}
		Page(const int index, const string title) : title(title), pageIndex(index) {}
		~Page() { title.clear(); }
	protected:
		string title;
		int pageIndex;
	public:
		virtual void SetTitle(string title) = 0;
		virtual void Show() = 0;
		virtual EPage WaitInput() = 0;
	};
}

using namespace ccs;

#endif