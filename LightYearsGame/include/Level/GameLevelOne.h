#pragma once
#include "framework/World.h"
#include "framework/TimerManager.h"
namespace ly
{
	class PlayerSpaceship;
	class GameplayHUD;
	class GameLevelOne : public World
	{
	public:
		GameLevelOne(Application* owningApp);
	private:
		virtual void AllGameStageFinished() override;
		virtual void BeginPlay() override;
		weak<PlayerSpaceship> mPlayerSpaceship;
		weak<GameplayHUD> mGameplayHUD;
		void PlayerSpaceshipDestroyed(Actor* destoryedPlayerSpaceship);
		TimerHandle timerHandle_Test;
		virtual void InitGameStages() override;
		void QuitGame();
		void Restart();
		void GameOver();
		void SpawnCosmetics();
	};
}