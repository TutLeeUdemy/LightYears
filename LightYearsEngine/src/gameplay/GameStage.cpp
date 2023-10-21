#include "gameplay/GameStage.h"
#include "framework/Core.h"
namespace ly
{
	GameStage::GameStage(World* world)
		: mWorld{world},
		mStageFinished{false}
	{

	}
	
	void GameStage::StartStage()
	{
		LOG("Stage Started");
	}
	
	void GameStage::TickStage(float deltaTime)
	{
		LOG("Stage Tikcing");
	}
	
	void GameStage::FinishStage()
	{
		onStageFinished.Broadcast();
		mStageFinished = true;
		StageFinished();
	}

	void GameStage::StageFinished()
	{
		LOG("Stage Finished");
	}
}