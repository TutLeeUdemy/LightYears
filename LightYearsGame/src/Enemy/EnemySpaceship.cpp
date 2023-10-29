#include "Enemy/EnemySpaceship.h"
#include "framework/MathUtility.h"

namespace ly
{
	EnemySpaceship::EnemySpaceship(World* owningWorld, const std::string& texturePath, float collisionDamage, const List<RewardFactoryFunc> rewards)
		: Spaceship{ owningWorld, texturePath }, mCollisionDamage{ collisionDamage }, mRewardFactories{rewards}
	{
		SetTeamID(2);
	}

	void EnemySpaceship::Tick(float deltaTime)
	{
		Spaceship::Tick(deltaTime);
		if(IsActorOutOfWindowBounds(GetActorGlobalBounds().width * 2.f))
		{
			Destory();
		}
	}

	void EnemySpaceship::SpawnReward()
	{
		if (mRewardFactories.size() == 0) return;

		int pick = (int)RandomRange(0, mRewardFactories.size());
		if (pick >= 0 && pick < mRewardFactories.size())
		{
			weak<Reward> newReward =  mRewardFactories[pick](GetWorld());
			newReward.lock()->SetActorLocation(GetActorLocation());
		}
	}

	void EnemySpaceship::OnActorBeginOverlap(Actor* other)
	{
		Spaceship::OnActorBeginOverlap(other);
		if (IsOtherHostile(other))
		{
			other->ApplyDamage(mCollisionDamage);
		}
	}
	void EnemySpaceship::Blew()
	{
		SpawnReward();
	}
}