#include "gameFramework/GameApplication.h"
#include "Level/GameLevelOne.h"
#include "framework/AssetManager.h"
#include "config.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{600, 980, "Light Years" , sf::Style::Titlebar | sf::Style::Close }
	{
		AssetManager::Get().SetAssetRootDirectory(GetResourceDir());
		weak<GameLevelOne> newWorld = LoadWorld<GameLevelOne>();
	}
}

