#include "framework/world.h"
#include "player/Reward.h"
#include "player/PlayerSpaceship.h"
#include "weapon/ThreeWayShooter.h"
#include "weapon/FrontalWiper.h"
#include "player/PlayerManager.h"

namespace ly
{
	Reward::Reward(World* world, const std::string& texturePath, RewardFunc rewardFunc, float speed)
		: Actor{ world, texturePath },
		mRewardFunc{ rewardFunc },
		mSpeed{ speed }
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
		AddActorLocationOffset({ 0.f, mSpeed * deltaTime });
	}

	void Reward::OnActorBeginOverlap(Actor* otherActor)
	{
		if (!otherActor || otherActor->IsPendingDestory())
			return;

		if (!PlayerManager::Get().GetPlayer())
			return;

		weak<PlayerSpaceship> playerSpaceship = PlayerManager::Get().GetPlayer()->GetCurrentSpaceship();
		if (playerSpaceship.expired() || playerSpaceship.lock()->IsPendingDestory())
			return;

		if (playerSpaceship.lock()->GetUniqueID() == otherActor->GetUniqueID())
		{
			mRewardFunc(playerSpaceship.lock().get());
			Destory();
		}
	}

	weak<Reward> CreateHealthReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/pickups/pill_green.png", RewardHealth);
	}

	weak<Reward> CreateThreewayShooterReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/pickups/three_shooter_pickup.png", RewardThreewayShooter);
	}

	weak<Reward> CreateFrontalWiperReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/pickups/front_row_shooter_pickup.png", RewardFrontalWiper);
	}

	weak<Reward> CreateLifeReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/pickups/playerLife1_blue.png", RewardLife);
	}

	weak<Reward> CreateReward(World* world, const std::string& texturePath, RewardFunc rewardFunc)
	{
		weak<Reward> reward = world->SpawnActor<Reward>(texturePath, rewardFunc);
		return reward;
	}

	void RewardHealth(PlayerSpaceship* player)
	{
		static float rewardAmt = 10.f;
		if (player && !player->IsPendingDestory())
		{
			player->GetHealthComp().ChangeHealth(rewardAmt);
		}
	}

	void RewardThreewayShooter(PlayerSpaceship* player)
	{
		if (player && !player->IsPendingDestory())
		{
			player->SetShooter(unique<Shooter>{new ThreeWayShooter{player, 0.4f, {50.f, 0.f} }});
		}
	}
	void RewardFrontalWiper(PlayerSpaceship* player)
	{
		if (player && !player->IsPendingDestory())
		{
			player->SetShooter(unique<Shooter>{new FrontalWiper{ player, 0.4f, {50.f, 0.f} }});
		}
	}
	void RewardLife(PlayerSpaceship* player)
	{
		if (!PlayerManager::Get().GetPlayer())
			return;

		PlayerManager::Get().GetPlayer()->AddLifeCount(1);
	}
}