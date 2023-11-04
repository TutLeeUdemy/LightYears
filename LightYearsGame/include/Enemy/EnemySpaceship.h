#pragma once

#include "spaceship/Spaceship.h"
#include "player/Reward.h"
namespace ly
{
	class EnemySpaceship : public Spaceship
	{
	public:
		EnemySpaceship(World* owningWorld, 
			const std::string& texturePath,
			float collisionDamage = 200.f,
			const List<RewardFactoryFunc> rewards = 
			{
				CreateHealthReward,
				CreateThreewayShooterReward,
				CreateFrontalWiperReward
			}
		);
		virtual void Tick(float deltaTime) override;
		void SetScoreAwardAmt(unsigned int amt);
	private:
		void SpawnReward();
		float mCollisionDamage;
		unsigned int scoreAwardAmt;
		virtual void OnActorBeginOverlap(Actor* other) override;
		virtual void Blew() override;
		List<RewardFactoryFunc> mRewardFactories;
	};
}