#pragma once

namespace ly
{
	class Object
	{
	public:
		Object();
		virtual ~Object();

		void Destory();
		bool IsPendingDestory() const { return mIsPendingDestory; }

	private:
		bool mIsPendingDestory;
	};
}