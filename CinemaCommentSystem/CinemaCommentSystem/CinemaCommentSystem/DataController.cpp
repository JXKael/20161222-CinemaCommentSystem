#include "DataController.h"
using namespace ccs;

DataController::DataController()
{
	cinemas = NULL;
}

DataController::~DataController()
{
	if (NULL != this->cinemas)
		delete this->cinemas;
}