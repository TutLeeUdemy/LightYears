#include "player/Reward.h"
#include "player/PlayerSpaceship.h"
namespace ly
{
	Reward::Reward(World* world, const std::string& texturePath, RewardFunc rewardFunc, float speed)
		: Actor{world, texturePath}, 
		mRewardFunc{rewardFunc},
		mSpeed{speed}
	{
	}
	void Reward::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);
	}
	void Reward::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorLocationOffset({0.f, mSpeed * deltaTime});
	}

	void Reward::OnActorBeginOverlap(Actor* otherActor)
	{
		//TODO: clean up casting.
		PlayerSpaceship* playerSpaceship = static_cast<PlayerSpaceship*>(otherActor);
		if (playerSpaceship != nullptr && !playerSpaceship->IsPendingDestory())
		{
			mRewardFunc(playerSpaceship);
		}
	}
}