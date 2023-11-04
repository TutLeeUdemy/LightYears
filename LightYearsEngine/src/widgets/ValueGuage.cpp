#include "widgets/ValueGuage.h"
#include "framework/AssetManager.h"
namespace ly
{

	ValueGuage::ValueGuage(const sf::Vector2f& size, float initialPercent, const sf::Color& foreGroundColor, const sf::Color& backgroundColor)
		: mTextFont{ AssetManager::Get().LoadFont("SpaceShooterRedux/Bonus/kenvector_future.ttf") },
		mText{ "",*(mTextFont.get()) },
		mBarFront{ size },
		mBarBack{ size },
		mPercent{ initialPercent },
		mForegroundColor{foreGroundColor},
		mBackgroundColor{backgroundColor}
	{
		mBarFront.setFillColor(mForegroundColor);
		mBarBack.setFillColor(mBackgroundColor);
		SetTextSize(20);
	}
	void ValueGuage::UpdateValue(float value, float maxValue)
	{
		LOG("player health is now: %f", value);
		if (maxValue == 0) return;
		mPercent = value / maxValue;
		std::string displayStr = std::to_string((int)value) + "/" + std::to_string((int)maxValue);
		mText.setString(displayStr);

		sf::Vector2f barSize = mBarBack.getSize();
		mBarFront.setSize({barSize.x * mPercent, barSize.y});
		CenterText();
	}

	sf::FloatRect ValueGuage::GetBound() const
	{
		return mBarBack.getGlobalBounds();
	}

	void ValueGuage::SetTextSize(unsigned int characterSize)
	{
		mText.setCharacterSize(characterSize);
	}

	void ValueGuage::SetForgroundColor(const sf::Color& color)
	{
		mBarFront.setFillColor(color);
	}

	void ValueGuage::SetBackgroundColor(const sf::Color& color)
	{
		mBarBack.setFillColor(color);
	}

	void ValueGuage::Draw(sf::RenderWindow& windowRef)
	{
		windowRef.draw(mBarBack);
		windowRef.draw(mBarFront);
		windowRef.draw(mText);
	}

	void ValueGuage::LocationUpdated(const sf::Vector2f& newLocation)
	{
		mBarFront.setPosition(newLocation);
		mBarBack.setPosition(newLocation);
		CenterText();
	}
	
	void ValueGuage::RotationUpdated(float newRotation)
	{
		mText.setRotation(newRotation);
		mBarFront.setRotation(newRotation);
		mBarBack.setRotation(newRotation);
	}

	void ValueGuage::CenterText()
	{
		sf::Vector2f widgetCenter = GetCenterPosition();
		sf::FloatRect textBound = mText.getGlobalBounds();
		mText.setPosition(widgetCenter - sf::Vector2f{textBound.width/2.f, textBound.height});
	}
}