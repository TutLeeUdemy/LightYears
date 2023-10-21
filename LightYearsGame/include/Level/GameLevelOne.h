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
		virtual void BeginPlay() override;
		weak<PlayerSpaceship> testPlayerSpaceship;
		void TimerCallBack_Test();
		unsigned int timerIndex_Test;
	};
}