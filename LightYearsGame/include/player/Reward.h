#pragma once

#include <functional>
#include "framework/Actor.h"
namespace ly
{
	class PlayerSpaceship;
	using RewardFunc = std::function<void(PlayerSpaceship*)>;
	class Reward : public Actor
	{
	public:
		Reward(World* world, const std::string& texturePath, RewardFunc rewardFunc, float speed = 200.f);
		virtual void BeginPlay() override;
		virtual void Tick(float deltaTime) override;
	private:
		virtual void OnActorBeginOverlap(Actor* otherActor) override;
		float mSpeed;
		RewardFunc mRewardFunc;
	};
}