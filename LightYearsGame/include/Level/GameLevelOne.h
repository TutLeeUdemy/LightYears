#pragma once
#include "framework/World.h"
#include "framework/TimerManager.h"
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
		TimerHandle timerHandle_Test;
		virtual void InitGameStages() override;
	};
}