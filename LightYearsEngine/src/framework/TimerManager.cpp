#include "framework/TimerManager.h"

namespace ly
{
	Timer::Timer(weak<Object> weakRef, std::function<void()> callback, float duration, bool repeat)
		: mListener{ weakRef, callback },
		mDuration{ duration },
		mRepeat{ repeat },
		mTimeCounter{ 0.f },
		mIsExpired{ false }
	{

	}

	void Timer::TickTime(float deltaTime)
	{
		if (Expired())
		{
			return;
		}

		mTimeCounter += deltaTime;
		if (mTimeCounter >= mDuration)
		{
			mListener.second();

			if (mRepeat)
			{
				mTimeCounter = 0.f;
			}
			else
			{
				SetExpired();
			}
		}
	}

	bool Timer::Expired() const
	{
		return mIsExpired || mListener.first.expired() || mListener.first.lock()->IsPendingDestory();
	}

	void Timer::SetExpired()
	{
		mIsExpired = true;
	}

	unsigned int TimerManager::timerIndexCounter = 0;

	unique<TimerManager> TimerManager::timerManager{ nullptr };
	
	TimerManager::TimerManager() : mTimers{}
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

	void TimerManager::UpdateTimer(float deltaTime)
	{
		for (auto iter = mTimers.begin(); iter != mTimers.end();)
		{
			if (iter->second.Expired())
			{
				iter = mTimers.erase(iter);
			}
			else
			{
				iter->second.TickTime(deltaTime);
				++iter;
			}
		}
	}

	void TimerManager::ClearTimer(unsigned int timerIndex)
	{
		auto iter = mTimers.find(timerIndex);
		if (iter != mTimers.end())
		{
			iter->second.SetExpired();
		}
	}
}