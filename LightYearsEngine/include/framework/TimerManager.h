#include "framework/Core.h"
#include "framework/Object.h"

namespace ly
{
	class TimerManager
	{
	public:
		static TimerManager& Get();
		template<typename ClassName>
		void SetTimer(weak<Object> weakRef, void(ClassName::* callback)(), float duration, bool repeat = false)
		{

		}
	protected:
		TimerManager();
	private:
		static unique<TimerManager> timerManager;
	};
}