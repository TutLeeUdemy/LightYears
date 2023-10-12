#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"

int main()
{
	//allowcating on the heap.
	std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();
	app->Run();
}