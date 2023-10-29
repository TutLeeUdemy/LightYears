#include "weapon/Shooter.h"

namespace ly
{
	void Shooter::Shoot()
	{
		if (CanShoot() && !IsOnCooldown())
		{
			ShootImpl();
		}
	}
	
	void Shooter::IncrementLevel(int amt)
	{
		if (mCurrentLevel == mMaxLevel) return;
		++mCurrentLevel;
	}

	Shooter::Shooter(Actor* owner)
		: mOwner{owner},
		mCurrentLevel{1},
		mMaxLevel{4}
	{

	}
}
