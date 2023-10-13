#include "EntryPoint.h"
#include "framework/Application.h"

int main()
{
	ly::Application* app = GetApplication();
	app->Run();
	delete app;
}