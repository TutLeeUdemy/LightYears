#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
		newWorld.lock()->SpawnActor<Actor>();
	}
}

