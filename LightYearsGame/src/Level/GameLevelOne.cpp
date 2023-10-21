#include "Level/GameLevelOne.h"
#include "Enemy/Vanguard.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "framework/TimerManager.h"
#include "framework/World.h"

#include "player/PlayerSpaceship.h"
namespace ly
{
	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{
		testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
		testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
		testPlayerSpaceship.lock()->SetActorRotation(-90.f);

		weak<Vangaurd> testSpaceship = SpawnActor<Vangaurd>();
		testSpaceship.lock()->SetActorLocation(sf::Vector2f{ 100.f, 50.f });
	}

	void GameLevelOne::BeginPlay()
	{
		timerIndex_Test = TimerManager::Get().SetTimer(GetWeakRef(), &GameLevelOne::TimerCallBack_Test, 2, true);
	}

	void GameLevelOne::TimerCallBack_Test()
	{
		LOG("Callback called!");
		TimerManager::Get().ClearTimer(timerIndex_Test);
	}
}