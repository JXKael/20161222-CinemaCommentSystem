#ifndef VIEW_CONTROLLER_H
#define VIEW_CONTROLLER_H

#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "View\Views.h"

class ViewController
{
public:
	ViewController();
	~ViewController();

private:
	Page *pageStack[10];
	int pageNum;
	bool isCurrendShowed;
	Page *currentPage;

public:
	void UpdateView();
	void ShowCurrentPage();
	EPage WaitInput();
	void GoTo(EPage page);
	void Back();
};

#endif