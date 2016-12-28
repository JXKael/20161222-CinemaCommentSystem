#ifndef VIEW_CONTROLLER_H
#define VIEW_CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "SystemController.h"
#include "View\Views.h"

namespace ccs
{
	class ViewController {
	public:
		ViewController();
		ViewController(SystemController *systemController);
		~ViewController();

	private:
		Page *pageStack[10];
		int pageNum;
		bool isCurrendShowed;
		Page *currentPage;
		SystemController *systemController;
	public:
		void UpdateView();
		void ShowCurrentPage();
		EPage WaitInput();
		void GoTo(EPage page);
		void Back();
	};
}

using namespace ccs;

#endif