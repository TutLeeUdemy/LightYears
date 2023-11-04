#include "framework/Actor.h"
#include "widgets/GameplayHUD.h"
#include "player/Player.h"
#include "player/PlayerManager.h"
#include "player/PlayerSpaceship.h"
namespace ly
{
	GameplayHUD::GameplayHUD()
		:mFramerateText{"Frame Rate:"},
		mPlayerHealthBar{},
		mPlayerLifeIcon{ "SpaceShooterRedux/PNG/pickups/playerLife1_blue.png" },
		mPlayerLifeText{ "" },
		mPlayerScoreIcon{ "SpaceShooterRedux/PNG/Power-ups/star_gold.png" },
		mPlayerScoreText{ "" },
		mHealthyHealthBarColor{128,255,128,255},
		mCriticalHealthBarColor{255,0,0,255},
		mCriticalThreshold{0.3},
		mWidgetSpaceing{10.f},
		TestButton{}
	{
		mFramerateText.SetTextSize(30);
		mPlayerLifeText.SetTextSize(20);
		mPlayerScoreText.SetTextSize(20);
	}
	void GameplayHUD::Draw(sf::RenderWindow& windowRef)
	{
		mFramerateText.NativeDraw(windowRef);
		mPlayerHealthBar.NativeDraw(windowRef);
		mPlayerLifeIcon.NativeDraw(windowRef);
		mPlayerLifeText.NativeDraw(windowRef);
		mPlayerScoreIcon.NativeDraw(windowRef);
		mPlayerScoreText.NativeDraw(windowRef);
		TestButton.NativeDraw(windowRef);
	}

	void GameplayHUD::Tick(float deltaTime)
	{
		int frameRate = int(1 / deltaTime);
		std::string frameRateStr = "Frame Rate: " + std::to_string(frameRate);
		mFramerateText.SetString(frameRateStr);
	}
	void GameplayHUD::Init(const sf::RenderWindow& windowRef)
	{
		auto windowSize = windowRef.getSize();
		mPlayerHealthBar.SetWidgetLocation(sf::Vector2f{ 20.f, windowSize.y - 50.f });

		sf::Vector2f nextWidgetPos = mPlayerHealthBar.GetWidgetLocation();

		nextWidgetPos += sf::Vector2f{ mPlayerHealthBar.GetBound().width + mWidgetSpaceing, 0.f };
		mPlayerLifeIcon.SetWidgetLocation(nextWidgetPos);

		nextWidgetPos += sf::Vector2f{ mPlayerLifeIcon.GetBound().width + mWidgetSpaceing, 0.f };
		mPlayerLifeText.SetWidgetLocation(nextWidgetPos);

		nextWidgetPos += sf::Vector2f{ mPlayerLifeText.GetBound().width + mWidgetSpaceing * 4, -2.f };
		mPlayerScoreIcon.SetWidgetLocation(nextWidgetPos);

		nextWidgetPos += sf::Vector2f{ mPlayerScoreIcon.GetBound().width + mWidgetSpaceing, 0.f };
		mPlayerScoreText.SetWidgetLocation(nextWidgetPos);

		TestButton.SetWidgetLocation({windowSize.x/2.f, windowSize.y/2.f});

		RefreshHealthBar();
		ConnectPlayerStatus();
	}
	void GameplayHUD::PlayerHealthUpdated(float amt, float currentHealth, float maxHealth)
	{
		mPlayerHealthBar.UpdateValue(currentHealth, maxHealth);
		if (currentHealth / maxHealth < mCriticalThreshold)
		{
			mPlayerHealthBar.SetForgroundColor(mCriticalHealthBarColor);
		}
		else
		{
			mPlayerHealthBar.SetForgroundColor(mHealthyHealthBarColor);
		}
	}

	void GameplayHUD::PlayerLifeCountUpdated(int amt)
	{
		mPlayerLifeText.SetString(std::to_string(amt));
	}

	void GameplayHUD::PlayerScoreUpdated(int newScore)
	{
		mPlayerScoreText.SetString(std::to_string(newScore));
	}

	void GameplayHUD::RefreshHealthBar()
	{
		Player* player = PlayerManager::Get().GetPlayer();
		if (player && !player->GetCurrentSpaceship().expired())
		{
			weak<PlayerSpaceship> playerSpaceship = player->GetCurrentSpaceship();
			playerSpaceship.lock()->onActoryDestoryed.BindAction(GetWeakRef(), &GameplayHUD::PlayerSpaceshipDestoryed);
			HealthComponent& healthComp = player->GetCurrentSpaceship().lock()->GetHealthComp();
			healthComp.onHealthChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerHealthUpdated);
			PlayerHealthUpdated(0, healthComp.GetHealth(), healthComp.GetMaxHealth());
		}
	}

	void GameplayHUD::ConnectPlayerStatus()
	{
		Player* player = PlayerManager::Get().GetPlayer();
		if (player)
		{
			int lifeCount = player->GetLifeCount();
			mPlayerLifeText.SetString(std::to_string(lifeCount));
			player->onLifeChange.BindAction(GetWeakRef(), &GameplayHUD::PlayerLifeCountUpdated);

			int playerScore = player->GetScore();
			mPlayerScoreText.SetString(std::to_string(playerScore));
			player->onScoreChange.BindAction(GetWeakRef(), &GameplayHUD::PlayerScoreUpdated);
		}
	}
	void GameplayHUD::PlayerSpaceshipDestoryed(Actor* actor)
	{
		RefreshHealthBar();
	}
}