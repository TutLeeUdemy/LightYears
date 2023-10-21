#include "framework/TimerManager.h"

namespace ly
{
	unique<TimerManager> TimerManager::timerManager{ nullptr };
	
	TimerManager::TimerManager()
	{
	}
	TimerManager& TimerManager::Get()
	{
		if (!timerManager)
		{
			timerManager = std::move(unique<TimerManager>(new TimerManager{}));
		}

		return *timerManager;
	}
}