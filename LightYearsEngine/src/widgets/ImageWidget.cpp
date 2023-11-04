#include "widgets/ImageWidget.h"
#include "framework/AssetManager.h"
namespace ly
{
	ImageWidget::ImageWidget(const std::string& imagePath)
		: mTexture{AssetManager::Get().LoadTexture(imagePath)},
		mSprite{*(mTexture.get())}
	{
	}
	void ImageWidget::SetImage(const shared<sf::Texture>& newTexture)
	{
		if (newTexture)
		{
			mTexture = newTexture;
			mSprite.setTexture(*(mTexture.get()));
		}
	}
	void ImageWidget::LocationUpdated(const sf::Vector2f& newLocation)
	{
		mSprite.setPosition(newLocation);
	}

	void ImageWidget::RotationUpdated(float newRotation)
	{
		mSprite.setRotation(newRotation);
	}

	void ImageWidget::Draw(sf::RenderWindow& winowRef)
	{
		winowRef.draw(mSprite);
	}

	sf::FloatRect ImageWidget::GetBound() const
	{
		return mSprite.getGlobalBounds();
	}
}