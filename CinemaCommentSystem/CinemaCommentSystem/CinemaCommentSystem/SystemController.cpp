#include "SystemController.h"

SystemController::SystemController()
{
	this->dataController = NULL;
}

SystemController::SystemController(DataController *dataController)
{
	this->dataController = dataController;
}

SystemController::~SystemController()
{
	if (NULL != this->dataController)
		delete this->dataController;
}