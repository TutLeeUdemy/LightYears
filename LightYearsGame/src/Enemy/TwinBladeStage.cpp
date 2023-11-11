#include "Enemy/TwinBladeStage.h"
#include "Enemy/TwinBlade.h"
#include "framework/World.h"

#include "weapon/BulletShooter.h"
namespace ly
{
	TwinBladeStage::TwinBladeStage(World* world)
		: GameStage{world},
		mSpawnInterval{1.5f},
		mSpawnDistanceToCenter{100.f},
		mLeftSpawnLoc{world->GetWindowSize().x/2.f - mSpawnDistanceToCenter, -100.f},
		mRightSpawnLoc{world->GetWindowSize().x/2.f + mSpawnDistanceToCenter, -100.f},
		mSpawnLoc{mLeftSpawnLoc},
		mSpawnAmt{10},
		mCurrentSpawnCount{0}
	{
	}

	void TwinBladeStage::StartStage()
	{
		mSpawnTimerHandle = TimerManager::Get().SetTimer(GetWeakRef(), &TwinBladeStage::SpawnTwinBlade, mSpawnInterval, true);
	}

	void TwinBladeStage::SpawnTwinBlade()
	{
		weak<TwinBlade> newTwinBlade = GetWorld()->SpawnActor<TwinBlade>();
		newTwinBlade.lock()->SetActorLocation(mSpawnLoc);
		if (mSpawnLoc == mLeftSpawnLoc)
		{
			mSpawnLoc = mRightSpawnLoc;
		}
		else
		{
			mSpawnLoc = mLeftSpawnLoc;
		}

		++mCurrentSpawnCount;
		if (mCurrentSpawnCount == mSpawnAmt)
		{
			FinishStage();
		}
	}

	void TwinBladeStage::StageFinished()
	{
		TimerManager::Get().ClearTimer(mSpawnTimerHandle);
	}
}