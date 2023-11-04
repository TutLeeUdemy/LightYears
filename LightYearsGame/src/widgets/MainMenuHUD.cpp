#include "widgets/MainMenuHUD.h"

namespace ly
{
	MainMenuHUD::MainMenuHUD()
		: mTitleText{"Light Years"},
		mStartButton{"Start"},
		mQuitButton{"Quit"}
	{
		mTitleText.SetTextSize(40);
		mStartButton.SetTextSize(20);
		mQuitButton.SetTextSize(20);
	}
	void MainMenuHUD::Draw(sf::RenderWindow& windowRef)
	{
		mTitleText.NativeDraw(windowRef);
		mStartButton.NativeDraw(windowRef);
		mQuitButton.NativeDraw(windowRef);
	}
	bool MainMenuHUD::HandleEvent(const sf::Event& event)
	{
		return mStartButton.HandleEvent(event) ||
			   mQuitButton.HandleEvent(event) ||
			   HUD::HandleEvent(event);
	}

	void MainMenuHUD::Init(const sf::RenderWindow& windowRef)
	{
		sf::Vector2u windowSize = windowRef.getSize();
		mTitleText.SetWidgetLocation({ windowSize.x / 2.f - mTitleText.GetBound().width/2.f, 100.f});

		mStartButton.SetWidgetLocation({windowSize.x / 2.f-mStartButton.GetBound().width/2.f, windowSize.y / 2.f});
		mQuitButton.SetWidgetLocation(mStartButton.GetWidgetLocation() + sf::Vector2f{0.f, 50.f});
		mStartButton.onButtonClicked.BindAction(GetWeakRef(), &MainMenuHUD::StartButtonClicked);
		mQuitButton.onButtonClicked.BindAction(GetWeakRef(), &MainMenuHUD::QuitButtonClicked);
	}
	void MainMenuHUD::StartButtonClicked()
	{
		onStartButtonClicked.Broadcast();
	}
	void MainMenuHUD::QuitButtonClicked()
	{
		onQuitButtonClicked.Broadcast();
	}
}