#include "ViewController.h"
using namespace ccs;

ViewController::ViewController()
{
	this->pageNum = 0;
	this->systemController = NULL;
	this->isCurrendShowed = false;
	
	this->currentPage = new PageWelcome(pageNum);
	this->pageStack[pageNum] = currentPage;
	++pageNum;
}

ViewController::ViewController(SystemController *systemController)
{
	this->pageNum = 0;
	this->systemController = systemController;
	this->isCurrendShowed = false;

	this->currentPage = new PageWelcome(pageNum);
	this->pageStack[pageNum] = currentPage;
	++pageNum;
}


ViewController::~ViewController()
{
	if (NULL != currentPage)
		delete currentPage;

	for (int i = 0; i < 10; ++i)
	{
		if (NULL != currentPage)
			delete pageStack[i];
	}
}

void ViewController::UpdateView()
{
	ShowCurrentPage();
}

void ViewController::ShowCurrentPage()
{
	if (NULL != currentPage)
	{
		if (!isCurrendShowed)
		{
			currentPage->Show();
			isCurrendShowed = true;
			GoTo(this->WaitInput());
		}
	}
}

EPage ViewController::WaitInput()
{
	if (NULL != currentPage)
		return currentPage->WaitInput();
}

void ViewController::GoTo(EPage page)
{
	switch (page)
	{
		case E_PAGE_WELCOME:
		{
			// 欢迎菜单
			currentPage = new PageWelcome(pageNum);
			break;
		}
		case E_PAGE_MAIN_MENU:
		{
			// 主菜单
			currentPage = new PageMainMenu(pageNum);
			break;
		}
		case E_PAGE_NORMAL_USER_MENU:
		{
			// 普通用户菜单
			currentPage = new PageNormalUserMenu(pageNum);
			break;
		}
		case E_PAGE_MANAGER_MENU:
		{
			// 管理员菜单
			currentPage = new PageManagerMenu(pageNum);
			break;
		}
		case E_PAGE_QUIT:
		{
			// 谢谢使用界面
			currentPage = new PageQuit(pageNum);
			break;
		}
		case E_BACK:
		{
			// 返回命令
			Back();
			break;
		}
		case E_QUIT:
		{
			// 退出命令
			currentPage = NULL;
			systemController->isAppRuning = false;
			break;
		}
		default:
		{
			currentPage = NULL;
			break;
		}
	}

	if (NULL != currentPage && page != E_BACK)
	{
		pageStack[pageNum] = currentPage;
		++pageNum;
		isCurrendShowed = false;
	}
}

void ViewController::Back()
{
	if (pageNum > 1)
	{
		delete currentPage;
		pageStack[pageNum - 1] = NULL;
		--pageNum;

		currentPage = pageStack[pageNum - 1];
		isCurrendShowed = false;
	}
}