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
		E_PAGE_MAIN
	};

	class Page {
	public:
		Page() : title("") {}
		Page(const int index) : pageIndex(index) {}
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