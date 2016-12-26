#include "ViewController.h"


ViewController::ViewController()
{
	currentPage = new PageWelcome();
}

ViewController::~ViewController()
{
	if (NULL != currentPage)
		delete currentPage;
}

void ViewController::GoTo(EPage page)
{
	switch (page)
	{
	case welcome:
		if (NULL != currentPage)
			delete currentPage;
		currentPage = new PageWelcome();
		break;
	default:
		break;
	}

	if (NULL != currentPage)
		this->ShowCurrentPage();
}