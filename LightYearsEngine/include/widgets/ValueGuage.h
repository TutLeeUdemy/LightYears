#pragma once
#include "widgets/Widget.h"

namespace ly
{
	class ValueGuage : public Widget
	{
	public:
		ValueGuage(const sf::Vector2f& size = sf::Vector2f{ 200.f, 30.f },
			float initialPercent = 0.75f,
			const sf::Color& foreGroundColor = sf::Color{ 128,255,128,255 },
			const sf::Color& backgroundColor = sf::Color{128,128,128,255});

		void UpdateValue(float value, float maxValue);
		virtual sf::FloatRect GetBound() const;

		void SetTextSize(unsigned int characterSize);

		void SetForgroundColor(const sf::Color& color);
		void SetBackgroundColor(const sf::Color& color);

	private:
		virtual void Draw(sf::RenderWindow& windowRef) override;
		virtual void LocationUpdated(const sf::Vector2f& newLocation) override;
		virtual void RotationUpdated(float newRotation) override;
		void CenterText();
		shared<sf::Font> mTextFont;
		sf::Text mText;

		sf::RectangleShape mBarFront;
		sf::RectangleShape mBarBack;

		sf::Color mForegroundColor;
		sf::Color mBackgroundColor;

		float mPercent;
	};
}