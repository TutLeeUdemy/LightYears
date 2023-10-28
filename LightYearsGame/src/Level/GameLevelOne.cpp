#include "Level/GameLevelOne.h"
#include "Enemy/UFO.h"
#include "Enemy/Vanguard.h"
#include "Enemy/HexagonStage.h"
#include "Enemy/TwinBladeStage.h"
#include "Enemy/VanguardStage.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "framework/TimerManager.h"
#include "framework/World.h"
#include "gameplay/GameStage.h"
#include "gameplay/WaitStage.h"
#include "player/PlayerSpaceship.h"
#include "Enemy/Hexagon.h"
namespace ly
{
	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{
		testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
		testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
		testPlayerSpaceship.lock()->SetActorRotation(-90.f);
	}

	void GameLevelOne::BeginPlay()
	{
		weak<UFO> testUFO = SpawnActor<UFO>(sf::Vector2f{0.f, 0.f});
		testUFO.lock()->SetActorLocation({ GetWindowSize().x / 2.f, GetWindowSize().y / 2.f });
	}

	void GameLevelOne::InitGameStages()
	{
		AddStage(shared<WaitStage>{new WaitStage{this, 5.f}});
		AddStage(shared<VanguardStage>{new VanguardStage{this}});
		
		AddStage(shared<WaitStage>{new WaitStage{this, 15.f}});
		AddStage(shared<TwinBladeStage>{new TwinBladeStage{this}});
		
		AddStage(shared<WaitStage>{new WaitStage{this, 15.f}});
		AddStage(shared<HexagonStage>{new HexagonStage{ this }});
	}
}