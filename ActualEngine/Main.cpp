#include "App/AppWindow.h"

int main()
{

	try
	{
		AppWindow app;
		while (app.running()) {
			app.broadcast();
		}
	}
	catch (...) {
		//TODO: release things
		return -1;
	}

	return 0;
}