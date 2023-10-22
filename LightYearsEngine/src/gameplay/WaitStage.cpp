#include "framework/TimerManager.h"
#include "gameplay/WaitStage.h"
namespace ly
{
	WaitStage::WaitStage(World* world, float waitDuration)
		: GameStage{world},
		mWaitDuration{waitDuration}
	{
	}
	void WaitStage::StartStage()
	{
		TimerManager::Get().SetTimer(GetWeakRef(), &WaitStage::FinishStage, mWaitDuration);
	}
}