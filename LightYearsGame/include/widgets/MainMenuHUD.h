#pragma once

#include "widgets/HUD.h"
#include "widgets/Button.h"
#include "widgets/TextWidget.h"
namespace ly
{
	class MainMenuHUD : public HUD
	{
	public:
		MainMenuHUD();

		virtual void Draw(sf::RenderWindow& windowRef) override;
		virtual bool HandleEvent(const sf::Event& event) override;
		Delegate<> onStartButtonClicked;
		Delegate<> onQuitButtonClicked;
	private:

		virtual void Init(const sf::RenderWindow& windowRef) override;

		TextWidget mTitleText;
		Button mStartButton;
		Button mQuitButton;

		void StartButtonClicked();
		void QuitButtonClicked();
	};
}