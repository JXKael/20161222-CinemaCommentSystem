#include "DataController.h"

DataController::DataController()
{
	cinemas = NULL;
}

DataController::~DataController()
{
	if (NULL != this->cinemas)
		delete this->cinemas;
}