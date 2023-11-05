#include "Enemy/Boss.h"
#include "gameplay/HealthComponent.h"
namespace ly
{
	Boss::Boss(World* world)
		: EnemySpaceship{world, "SpaceShooterRedux/PNG/Enemies/boss.png" },
		mSpeed{100.f},
		mBaseSpeed{100.f},
		mSwitchDistanceToEdge{100.f},
		mBaseShooterLeft{ this, 1.f, {50.f, -50.f} },
		mBaseShooterRight{ this, 1.f, {50.f, 50.f} },
		mThreeWayShooter{ this, 4.f, {100.f, 0.f} },
		mFrontalWiperLeft{ this, 5.f, {80.f, -100} },
		mFrontalWiperRight{ this, 5.f, {80.f, 100} },
		mFinalStageShooterLeft{ this, 0.3f, {50, -150.f} },
		mFinalStageShooterRight{ this, 0.3f, {50, 150.f} },
		mStage{1}
	{
		SetActorRotation(90.f);
		SetVelocity({mSpeed, 0.f});
		SetRewardSpawnWeight(0.f);
	}

	void Boss::Tick(float deltaTime)
	{
		EnemySpaceship::Tick(deltaTime);
		ShootBaseShooters();
		ShootFrotnalWipers();
		ShootThreeWayShooter();
		if (mStage == 4)
		{
			mFinalStageShooterLeft.Shoot();
			mFinalStageShooterRight.Shoot();
		}
		CheckMove();
	}

	void Boss::BeginPlay()
	{
		EnemySpaceship::BeginPlay();
		HealthComponent& healthComp = GetHealthComp();
		healthComp.SetInitialHealth(3000.f, 3000.f);
		healthComp.onHealthChanged.BindAction(GetWeakRef(), &Boss::HealthChanged);
	}

	void Boss::CheckMove()
	{
		if (GetActorLocation().x > GetWindowSize().x - mSwitchDistanceToEdge)
		{
			SetVelocity({ -mSpeed, 0.f });
		}
		else if (GetActorLocation().x < mSwitchDistanceToEdge)
		{
			SetVelocity({mSpeed, 0.f});
		}
	}

	void Boss::ShootBaseShooters()
	{
		mBaseShooterLeft.Shoot();
		mBaseShooterRight.Shoot();
	}
	
	void Boss::ShootThreeWayShooter()
	{
		mThreeWayShooter.Shoot();
	}

	void Boss::ShootFrotnalWipers()
	{
		mFrontalWiperLeft.Shoot();
		mFrontalWiperRight.Shoot();
	}

	void Boss::HealthChanged(float amt, float currentHealth, float maxHealth)
	{
		float percentLeft = currentHealth / maxHealth;
		if (percentLeft < 0.7 && percentLeft > 0.5)
		{
			SetStage(2);
		}

		if (percentLeft < 0.5 && percentLeft > 0.3)
		{
			SetStage(3);
		}

		if (percentLeft < 0.3)
		{
			SetStage(4);
		}
	}
	void Boss::SetStage(int newStage)
	{
		mStage = newStage;
		mBaseShooterLeft.SetCurrentLevel(mStage);
		mBaseShooterRight.SetCurrentLevel(mStage);
		mFrontalWiperLeft.SetCurrentLevel(mStage);
		mFrontalWiperRight.SetCurrentLevel(mStage);
		mThreeWayShooter.SetCurrentLevel(mStage);
		mSpeed = mStage * mBaseSpeed;
	}
}