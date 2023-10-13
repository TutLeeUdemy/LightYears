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
		actorToDestory = newWorld.lock()->SpawnActor<Actor>();
		counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (!actorToDestory.expired())
			{
				actorToDestory.lock()->Destory();
			}
		}
	}
}

