#pragma once
#include <SFML/Graphics.hpp>
#include "widgets/Widget.h"

namespace ly
{
	class ImageWidget : public Widget
	{
	public:
		ImageWidget(const std::string& imagePath);

		void SetImage(const shared<sf::Texture>& newTexture);
		virtual sf::FloatRect GetBound() const override;
	private:
		virtual void LocationUpdated(const sf::Vector2f& newLocation) override;
		virtual void RotationUpdated(float newRotation) override;
		virtual void Draw(sf::RenderWindow& winowRef) override;
		shared<sf::Texture> mTexture;
		sf::Sprite mSprite;
	};
}