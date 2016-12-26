#include "Main.h"
using namespace std;

void main()
{
	SystemController *systemController = new SystemController();
	ViewController * viewController = new ViewController();
	while (true)
	{
		viewController->UpdateView();
	}
}