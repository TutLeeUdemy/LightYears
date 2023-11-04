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
		mHealthyHealthBarColor{128,255,128,255},
		mCriticalHealthBarColor{255,0,0,255},
		mCriticalThreshold{0.3},
		mPlayerLifeIcon{ "SpaceShooterRedux/PNG/pickups/playerLife1_blue.png" },
		mWidgetSpaceing{10.f}
	{
		mFramerateText.SetTextSize(30);
	}
	void GameplayHUD::Draw(sf::RenderWindow& windowRef)
	{
		mFramerateText.NativeDraw(windowRef);
		mPlayerHealthBar.NativeDraw(windowRef);
		mPlayerLifeIcon.NativeDraw(windowRef);
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
		mPlayerHealthBar.SetWidgetLocation(sf::Vector2f{20.f, windowSize.y - 50.f});
		sf::Vector2f lifeIconPos = mPlayerHealthBar.GetWidgetLocation();
		lifeIconPos += sf::Vector2f{ mPlayerHealthBar.GetBound().width + mWidgetSpaceing, 0.f };
		mPlayerLifeIcon.SetWidgetLocation(lifeIconPos);

		RefreshHealthBar();
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
	void GameplayHUD::RefreshHealthBar()
	{
		Player* player = PlayerManager::Get().GetPlayer();
		if (player && !player->GetCurrentSpaceship().expired())
		{
			weak<PlayerSpaceship> playerSpaceship = player->GetCurrentSpaceship();
			playerSpaceship.lock()->onActoryDestoryed.BindAction(GetWeakRef(), &GameplayHUD::PlayerSpaceshipDestoryed);
			HealthComponent& healthComp = player->GetCurrentSpaceship().lock()->GetHealthComp();
			healthComp.onHealthChanged.BindAction(GetWeakRef(), &GameplayHUD::PlayerHealthUpdated);
			mPlayerHealthBar.UpdateValue(healthComp.GetHealth(), healthComp.GetMaxHealth());
		}
	}
	void GameplayHUD::PlayerSpaceshipDestoryed(Actor* actor)
	{
		RefreshHealthBar();
	}
}