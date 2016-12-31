#ifndef SYSTEM_CONTROLLER_H
#define SYSTEM_CONTROLLER_H

#include <iostream>

#include "DataController.h"

namespace ccs
{
	class SystemController {
	public:
		SystemController();
		SystemController(DataController *dataController);
		~SystemController();

	private:
		DataController * dataController;
	public:
		bool isAppRuning;
	};
}

#endif
