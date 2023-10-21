#pragma once
#include "framework/World.h"

namespace ly
{
	class PlayerSpaceship;
	class GameLevelOne : public World
	{
	public:
		GameLevelOne(Application* owningApp);
	private:
		weak<PlayerSpaceship> testPlayerSpaceship;
	};
}