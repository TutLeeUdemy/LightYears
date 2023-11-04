#pragma once
#include <memory>
#include "framework/Core.h"
#include "framework/Delegate.h"

namespace ly
{
	class Object : public std::enable_shared_from_this<Object>
	{
	public:
		Object();
		virtual ~Object();

		virtual void Destory();
		bool IsPendingDestory() const { return mIsPendingDestory; }

		weak<Object> GetWeakRef();
		weak<const Object> GetWeakRef() const;
		Delegate<Object*> onDestory;
		unsigned int GetUniqueID() const { return mUniqueID; }
	private:
		bool mIsPendingDestory;
		unsigned int mUniqueID;

		static unsigned int uniqueIDCounter;
		static unsigned int GetNextAvaliableID();
	};
}