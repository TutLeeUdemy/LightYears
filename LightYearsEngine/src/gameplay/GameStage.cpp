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
		
	}
	
	void GameStage::FinishStage()
	{
		mStageFinished = true;
		StageFinished();
		onStageFinished.Broadcast();
	}

	void GameStage::StageFinished()
	{
		LOG("Stage Finished");
	}
}