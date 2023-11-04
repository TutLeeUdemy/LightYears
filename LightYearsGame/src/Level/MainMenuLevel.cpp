#include "Level/MainMenuLevel.h"
#include "widgets/MainMenuHUD.h"
#include "framework/Application.h"
#include "Level/GameLevelOne.h"

namespace ly
{
	MainMenuLevel::MainMenuLevel(Application* owningApplication)
		: World{owningApplication}
	{
		mMainMenuHUD = SpawnHUD<MainMenuHUD>();
	}

	void MainMenuLevel::BeginPlay()
	{
		mMainMenuHUD.lock()->onStartButtonClicked.BindAction(GetWeakRef(), &MainMenuLevel::StartGame);
		mMainMenuHUD.lock()->onQuitButtonClicked.BindAction(GetWeakRef(), &MainMenuLevel::QuitGame);

	}

	void MainMenuLevel::StartGame()
	{
		GetApplication()->LoadWorld<GameLevelOne>();
	}

	void MainMenuLevel::QuitGame()
	{
		GetApplication()->QuitApplication();
	}


}