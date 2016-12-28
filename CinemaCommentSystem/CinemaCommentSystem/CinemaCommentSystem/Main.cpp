#include "Main.h"

void main()
{
	DataController *dataController = new DataController();
	SystemController *systemController = new SystemController(dataController);
	ViewController *viewController = new ViewController(systemController);
	while (true)
	{
		viewController->UpdateView();
	}
}