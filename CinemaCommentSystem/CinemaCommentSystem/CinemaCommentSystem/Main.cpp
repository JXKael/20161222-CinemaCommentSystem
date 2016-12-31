#include "Main.h"

using namespace std;
using namespace ccs;

void main()
{
	DataController *dataController = new DataController();
	SystemController *systemController = new SystemController(dataController);
	ViewController *viewController = new ViewController(systemController);
	while (systemController->isAppRuning)
	{
		viewController->UpdateView();
	}
}