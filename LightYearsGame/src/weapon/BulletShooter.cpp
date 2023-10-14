#include "framework/Core.h"
#include "weapon/BulletShooter.h"

namespace ly
{
	BulletShooter::BulletShooter(Actor* owner, float cooldownTime)
		: Shooter{owner},
		mCooldownClock{},
		mCooldownTime{cooldownTime}
	{

	}
	bool BulletShooter::IsOnCooldown() const
	{
		if (mCooldownClock.getElapsedTime().asSeconds() > mCooldownTime)
		{
			return false;
		}

		return true;
	}
	void BulletShooter::ShootImpl()
	{
		mCooldownClock.restart();
		LOG("Shooting!");
	}
}
