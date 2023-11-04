#pragma once

#include "widgets/Widget.h"
#include "framework/Delegate.h"

namespace ly
{
	class Button : public Widget
	{
	public:
		Button(const std::string& textString = "Button", const std::string& buttonTexturePath="SpaceShooterRedux/PNG/UI/buttonBlue.png");
		virtual sf::FloatRect GetBound() const;
	private:
		virtual void Draw(sf::RenderWindow& windowRef) override;
		virtual void LocationUpdated(const sf::Vector2f& location);
		virtual void RotationUpdated(float rotation);
		shared<sf::Texture> mButtonTexture;
		sf::Sprite mButtonSprite;

		shared<sf::Font> mButtonFont;
		sf::Text mButtonText;

		sf::Color mButtonDefaultColor;
		sf::Color mButtonDownColor;
		sf::Color mButtonHoverColor;

		bool mIsButtonDown;
	};
}