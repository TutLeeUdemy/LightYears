#pragma once
#include <SFML/Graphics.hpp>
#include "framework/TimerManager.h"
#include "gameplay/GameStage.h"
namespace ly
{
	class TwinBladeStage : public GameStage
	{
	public:
		TwinBladeStage(World* world);
		virtual void StartStage() override;
	private:

		void SpawnTwinBlade();
		virtual void StageFinished() override;

		float mSpawnInterval;
		float mSpawnDistanceToCenter;

		sf::Vector2f mLeftSpawnLoc;
		sf::Vector2f mRightSpawnLoc;
		sf::Vector2f mSpawnLoc;

		int mSpawnAmt;
		int mCurrentSpawnCount;

		TimerHandle mSpawnTimerHandle;
	};
}