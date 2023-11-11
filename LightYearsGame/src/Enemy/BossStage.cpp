#include "Enemy/BossStage.h"
#include "Enemy/Boss.h"
#include "framework/World.h"

#include "weapon/BulletShooter.h"
namespace ly
{
	BossStage::BossStage(World* world)
		: GameStage{world}
	{
	}
	void BossStage::StartStage()
	{
		weak<Boss> boss = GetWorld()->SpawnActor<Boss>();
		auto windowSize = GetWorld()->GetWindowSize();
		boss.lock()->SetActorLocation({ windowSize.x / 2.f, 200.f });
		boss.lock()->onActoryDestoryed.BindAction(GetWeakRef(), &BossStage::BossDestroyed);
	}
	void BossStage::BossDestroyed(Actor* bossActor)
	{
		FinishStage();
	}
}
