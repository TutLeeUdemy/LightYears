#include "gameFramework/GameApplication.h"
#include "framework/World.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}

