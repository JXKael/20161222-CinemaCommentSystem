#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "View\Page.h"
#include "View\Views.h"

#ifndef VIEW_CONTROLLER_H
#define VIEW_CONTROLLER_H

class ViewController
{
public:
	ViewController();
	~ViewController();

private:
	Page *currentPage;

public:
	inline void ShowCurrentPage(){ currentPage->Show(); }
	void GoTo(EPage page);
};

#endif