#ifndef DATA_CONTROLLER_H
#define DATA_CONTROLLER_H

#include "Data\Cinema.h"
#include "Data\CinemaType.h"
#include "Data\Elanguage.h"
#include "Data\ParameterString.h"

#include "Tools\LinkList.h"
#include "Tools\LinkNode.h"

using namespace tools;

namespace ccs
{
	class DataController {
	public:
		DataController();
		~DataController();
	private:
		LinkList<Cinema> *cinemas;
	};
}

using namespace ccs;

#endif // ! DATA_CONTROLLER_H