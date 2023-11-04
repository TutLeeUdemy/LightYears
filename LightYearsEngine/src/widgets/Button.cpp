#include "framework/AssetManager.h"
#include "widgets/Button.h"
namespace ly
{
	Button::Button(const std::string& textString, const std::string& buttonTexturePath)
		: mButtonTexture{ AssetManager::Get().LoadTexture(buttonTexturePath) },
		mButtonSprite{ *(mButtonTexture.get()) },
		mButtonFont{ AssetManager::Get().LoadFont("SpaceShooterRedux/Bonus/kenvector_future.ttf") },
		mButtonText(textString, *(mButtonFont.get())),
		mButtonDefaultColor{128,128,128,255},
		mButtonDownColor{64,64,64, 255},
		mButtonHoverColor{190, 190,190, 255},
		mIsButtonDown{false}
	{

	}
	void Button::Draw(sf::RenderWindow& windowRef)
	{
		windowRef.draw(mButtonSprite);
		windowRef.draw(mButtonText);
	}

	void Button::LocationUpdated(const sf::Vector2f& location)
	{
		mButtonSprite.setPosition(location);
		mButtonText.setPosition(location);
	}

	void Button::RotationUpdated(float rotation)
	{
		mButtonSprite.setRotation(rotation);
		mButtonText.setRotation(rotation);
	}

	sf::FloatRect Button::GetBound() const
	{
		return mButtonSprite.getGlobalBounds();
	}
}