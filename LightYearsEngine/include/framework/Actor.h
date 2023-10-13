#pragma once
#include "framework/Object.h"

namespace ly
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld);
		virtual ~Actor();
		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);
	private:
		World* mOwningWorld;
		bool mHasBeganPlay;
	};
}