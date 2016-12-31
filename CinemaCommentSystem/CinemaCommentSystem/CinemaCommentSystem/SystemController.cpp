#include "SystemController.h"
using namespace ccs;

SystemController::SystemController()
{
	isAppRuning = true;
	this->dataController = NULL;
}

SystemController::SystemController(DataController *dataController)
{
	isAppRuning = true;
	this->dataController = dataController;
}

SystemController::~SystemController()
{
	if (NULL != this->dataController)
		delete this->dataController;
}