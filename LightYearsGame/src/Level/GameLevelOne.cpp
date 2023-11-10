#include "Level/GameLevelOne.h"
#include "Enemy/UFO.h"
#include "Enemy/Vanguard.h"
#include "Enemy/HexagonStage.h"
#include "Enemy/TwinBladeStage.h"
#include "Enemy/UFOStage.h"
#include "Enemy/VanguardStage.h"
#include "framework/Actor.h"
#include "framework/Application.h"
#include "framework/AssetManager.h"
#include "framework/BackdropActor.h"
#include "framework/BackgroundLayer.h"
#include "framework/TimerManager.h"
#include "framework/World.h"
#include "gameplay/GameStage.h"
#include "gameplay/WaitStage.h"
#include "player/PlayerSpaceship.h"
#include "Enemy/Hexagon.h"
#include "Enemy/BossStage.h"
#include "Enemy/ChaosStage.h"

#include "player/PlayerManager.h"
#include "widgets/GameplayHUD.h"

namespace ly
{
	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{
		
	}

	void GameLevelOne::AllGameStageFinished()
	{
		mGameplayHUD.lock()->GameFinished(true);
	}

	void GameLevelOne::BeginPlay()
	{
		SpawnCosmetics();

		Player& newPlayer = PlayerManager::Get().CreateNewPlayer();
		mPlayerSpaceship = newPlayer.SpawnSpaceship(this);
		mPlayerSpaceship.lock()->onActoryDestoryed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceshipDestroyed);
		mGameplayHUD = SpawnHUD<GameplayHUD>();
		mGameplayHUD.lock()->onQuitBtnClicked.BindAction(GetWeakRef(), &GameLevelOne::QuitGame);
		mGameplayHUD.lock()->onRestartBtnClicked.BindAction(GetWeakRef(), &GameLevelOne::Restart);
	}

	void GameLevelOne::PlayerSpaceshipDestroyed(Actor* destoryedPlayerSpaceship)
	{
		mPlayerSpaceship = PlayerManager::Get().GetPlayer()->SpawnSpaceship(this);
		if (!mPlayerSpaceship.expired())
		{
			mPlayerSpaceship.lock()->onActoryDestoryed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceshipDestroyed);
		}
		else
		{
			GameOver();
		}
	}

	void GameLevelOne::InitGameStages()
	{
		AddStage(shared<WaitStage>{new WaitStage{this, 5.f}});
		AddStage(shared<VanguardStage>{new VanguardStage{this}});
		
		AddStage(shared<WaitStage>{new WaitStage{this, 15.f}});
		AddStage(shared<TwinBladeStage>{new TwinBladeStage{this}});
		
		AddStage(shared<WaitStage>{new WaitStage{this, 12.f}});
		AddStage(shared<HexagonStage>{new HexagonStage{ this }});

		AddStage(shared<WaitStage>{new WaitStage{this, 10.f}});
		AddStage(shared<UFOStage>{new UFOStage{ this }});

		AddStage(shared<WaitStage>{new WaitStage{this, 10.f}});
		AddStage(shared<ChaosStage>{new ChaosStage{ this }});

		AddStage(shared<WaitStage>{new WaitStage{ this, 10.f }});
		AddStage(shared<BossStage>{new BossStage{ this }});
	}

	void GameLevelOne::QuitGame()
	{
		GetApplication()->QuitApplication();
	}

	void GameLevelOne::Restart()
	{
		PlayerManager::Get().Reset();
		GetApplication()->LoadWorld<GameLevelOne>();
	}

	void GameLevelOne::GameOver()
	{
		mGameplayHUD.lock()->GameFinished(false);
	}

	void GameLevelOne::SpawnCosmetics()
	{
		auto backdropActor = SpawnActor<BackdropActor>("SpaceShooterRedux/Backgrounds/darkPurple.png");
		weak<BackgroundLayer> planets = SpawnActor<BackgroundLayer>();
		planets.lock()->SetAssets(
			{
				"SpaceShooterRedux/PNG/Planets/Planet1.png",
				"SpaceShooterRedux/PNG/Planets/Planet2.png",
				"SpaceShooterRedux/PNG/Planets/Planet3.png",
				"SpaceShooterRedux/PNG/Planets/Planet4.png",
				"SpaceShooterRedux/PNG/Planets/Planet5.png",
				"SpaceShooterRedux/PNG/Planets/Planet6.png",
				"SpaceShooterRedux/PNG/Planets/Planet7.png"
			}
		);

		planets.lock()->SetSpriteCount(1);
		planets.lock()->SetSizes(1, 1.5f);
		planets.lock()->SetVelocities({0, 30.f} ,{0, 80.f});


		weak<BackgroundLayer> meteors = SpawnActor<BackgroundLayer>();
		meteors.lock()->SetAssets(
			{
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_tiny1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_tiny2.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_big1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_big2.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_big3.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_big4.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_med1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_med3.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_small1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_small2.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny2.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_big1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_big2.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_big3.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_big4.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_med1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_med2.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_small1.png",
				"SpaceShooterRedux/PNG/Meteors/meteorGrey_small2.png"
			}
		);

		meteors.lock()->SetSpriteCount(20);
		meteors.lock()->SetSizes(.2f, .5f);
	}
}