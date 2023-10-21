#include <functional>
#include "framework/Core.h"
#include "framework/Object.h"

namespace ly
{
	struct Timer
	{
	public:
		Timer(weak<Object> weakRef, std::function<void()> callback, float duration, bool repeat);
		void TickTime(float deltaTime);
		bool Expired() const;
		void SetExpired();
	private:
		std::pair<weak<Object>, std::function<void()>> mListener;
		float mDuration;
		bool mRepeat;
		float mTimeCounter;
		bool mIsExpired;
	};

	class TimerManager
	{
	public:
		static TimerManager& Get();
		template<typename ClassName>
		unsigned int SetTimer(weak<Object> weakRef, void(ClassName::* callback)(), float duration, bool repeat = false)
		{
			++timerIndexCounter;
			mTimers.insert({ timerIndexCounter, Timer(weakRef, [=] {(static_cast<ClassName*>(weakRef.lock().get())->*callback)(); }, duration, repeat) });
			return timerIndexCounter;
		}

		void UpdateTimer(float deltaTime);
		void ClearTimer(unsigned int timerIndex);

	protected:
		TimerManager();
	private:
		static unique<TimerManager> timerManager;
		static unsigned int timerIndexCounter;
		Dictionary<unsigned int, Timer> mTimers;
	};
}